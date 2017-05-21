#include <hardware/hardware.h>
#include <hardware/led_hal.h>
#include <cutils/log.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include <utils/Log.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <android/log.h>  /* liblog */


static int fd;
static int led_open(struct led_device* leddev)
{
	ALOGI("led_open");
	fd = open("/dev/leds", O_RDWR);
	if (fd < 0)
	{
		ALOGI("led_open error");
	}
	return fd;
}

static int led_close(struct hw_device_t* device)
{
	ALOGI("led_close");
	close(fd);
	return 0;
}

static int led_ctrl(struct led_device* leddev, int status, int which)
{
	int ret = ioctl(fd, status, which);
	ALOGI("led_ctrl which %d static %d", which, status);
	return ret;
}

static int led_device_open(const hw_module_t* module, const char* id __unused,
                      hw_device_t** device __unused) {

    led_device_t *leddev = calloc(1, sizeof(led_device_t));

    if (!leddev) {
        ALOGE("Can not allocate memory for the led device");
        return -ENOMEM;
    }

    leddev->common.close = led_close;

    leddev->led_open = led_open;
    leddev->led_ctrl = led_ctrl;

    *device = (hw_device_t *) leddev;

    return 0;
}

static struct hw_module_methods_t led_module_methods = {
    .open = led_device_open,
};

struct hw_module_t HAL_MODULE_INFO_SYM = {
    .id = "led",
    .name = "led",
    .methods = &led_module_methods,
};

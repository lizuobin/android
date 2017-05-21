#define LOG_TAG "LedService"

#include "jni.h"
#include "JNIHelp.h"
#include "android_runtime/AndroidRuntime.h"

#include <utils/misc.h>
#include <utils/Log.h>

#include <stdio.h>
#include <hardware/led_hal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include <android/log.h>  /* liblog */

static hw_module_t *module;
static led_device_t *leddev;

static led_device_t* get_device(hw_module_t* module, char const* name)
{
    int err;
    hw_device_t* device;
    err = module->methods->open(module, name, &device);
    if (err == 0) {
        return (led_device_t*)device;
    } else {
        return NULL;
    }
}

jint ledOpen(JNIEnv *env, jobject cls)
{
	ALOGI("native ledOpen");
    	#if 1
	if (hw_get_module("led", (hw_module_t const**)&module) == 0)
	{
		leddev = get_device(module, "led");
		if (leddev == NULL)
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
	leddev->led_open(leddev);
	#endif
	return 0;
}

void ledClose(JNIEnv *env, jobject cls, jint a, jint b)
{
	leddev->led_close(leddev);
	ALOGI("native ledClose");
}

jint ledCtrl(JNIEnv *env, jobject cls, jint which, jint status)
{
	leddev->led_ctrl(leddev, status, which);
	ALOGI("native ledCtrl which %d static %d", which, status);
	return 0;
}

namespace android
{
	static JNINativeMethod method_table[] = {
		{ "native_Open", "()I", (void*)ledOpen },
		{ "native_Close", "()V", (void*)ledClose },
		{ "native_Ctrl", "(II)I", (void*)ledCtrl }
	};

	int register_android_server_LedService(JNIEnv *env)
	{
		return jniRegisterNativeMethods(env, "com/android/server/LedService",
				method_table, NELEM(method_table));
	}
};


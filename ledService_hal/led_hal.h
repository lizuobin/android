#ifndef _HARDWARE_LED_HAL_H
#define _HARDWARE_LED_HAL_H

#include <hardware/hardware.h>

__BEGIN_DECLS

struct led_device;
typedef struct led_device {
    struct hw_device_t common;
 
    int  (*led_open)(struct led_device* leddev);
    void (*led_close)(struct led_device* leddev);
    int  (*led_ctrl)(struct led_device* leddev, int which, int status);
} led_device_t;

__END_DECLS

#endif  // _HARDWARE_VIBRATOR_H

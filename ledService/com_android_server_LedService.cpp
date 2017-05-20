#define LOG_TAG "LedService"

#include "jni.h"
#include "JNIHelp.h"
#include "android_runtime/AndroidRuntime.h"

#include <utils/misc.h>
#include <utils/Log.h>
#include <hardware_legacy/vibrator.h>

#include <stdio.h>

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include <android/log.h>  /* liblog */

static jint fd;
jint ledOpen(JNIEnv *env, jobject cls)
{
	ALOGI("native ledOpen");
	fd = open("/dev/leds", O_RDWR);
	if (fd < 0)
	{
		ALOGI("native ledOpen error");
	}
	return fd;
}

void ledClose(JNIEnv *env, jobject cls, jint a, jint b)
{
	close(fd);
	ALOGI("native ledClose");
}

jint ledCtrl(JNIEnv *env, jobject cls, jint which, jint status)
{
	int ret = ioctl(fd, status, which);
	ALOGI("native ledCtrl which %d static %d", which, status);
	return ret;
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


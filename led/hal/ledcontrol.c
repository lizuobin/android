
#include <stdio.h>
#include <jni.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include <android/log.h>  /* liblog */

//__android_log_print(ANDROID_LOG_DEBUG, "JNIDemo", "native add ...");

/* java - c */
#if 0
typedef struct{
	char *name;		   	//name in java
	char *signature;	//params
	char *fnPtr;		//name in C
}JNINativeMethod;
#endif
static jint fd;
jint c_open(JNIEnv *env, jobject cls)
{
	__android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "native ledOpen");
	printf("%s\n",__func__);
	fd = open("/dev/leds", O_RDWR);
	if (fd < 0)
	{
		__android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "open error");
	}
}
void c_close(JNIEnv *env, jobject cls, jint a, jint b)
{
	__android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "native ledClose");
	printf("%s\n",__func__);
	close(fd);
}
jint c_ctrl(JNIEnv *env, jobject cls, jint which, jint status)
{
	printf("%s\n",__func__);
	int ret = ioctl(fd, status, which);
	__android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "native ledCtrl : %d, %d, %d", which, status, ret);
}


static const JNINativeMethod methods[] = {
	{"ledOpen", "()I", (void *)c_open},
	{"ledClose", "()V", (void *)c_close},
	{"ledCtrl", "(II)I", (void *)c_ctrl},
};
JNI_OnLoad(JavaVM *jvm, void *reserved)
{
	JNIEnv *env;
	jclass cls;
	if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)){
		return JNI_ERR;
	}
	//function of class in java
	cls = (*env)->FindClass(env, "com/example/hasee/hardlibrary/HardControl");
	if (cls == NULL){
		return JNI_ERR;
	}
	(*env)->RegisterNatives(env, cls, methods, sizeof(methods)/sizeof(methods[0]));
	return JNI_VERSION_1_4;
}





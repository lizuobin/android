package com.example.hasee.hardlibrary;

public class HardControl{
    public static native int ledOpen();
    public static native void ledClose();
    public static native int ledCtrl(int which, int status);
    static{
        /* ctrl + alt + t*/
        try {
            System.loadLibrary("ledcontrol");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
//package com.example.hasee.hardlibrary;

public class HardControl{
	static{
		/* ctrl + alt + t*/
		try {
			System.loadLibrary("hardcontrol");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}   
	
	public static native int ledOpen();
	public static native void ledClose();
	public static native int ledCtrl(int which, int status);

	public static void main(String args[]){
		HardControl hardcontrol = new HardControl();	
	}
}

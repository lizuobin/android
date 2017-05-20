package com.android.server;
import android.os.ILedService;
public class LedService extends ILedService.Stub{
	private static final String TAG = "LedService";
	/* call native c function */
	native public int  native_Ctrl(int which, int status);
	native public int  native_Open();
	native public void native_Close();
	public int ledCtrl(int which, int status)
	{
		return native_Ctrl(which, status);
	}
	public LedService(){
	
		native_Open();
	}
}

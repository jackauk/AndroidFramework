package com.android.androidframework.FrameworkUtils;

import android.app.Activity;
import android.content.Context;

public class SUtils{
    static final String TAG = "JA_LOGGER";
    static final String FILE = "SUtils.java ";
    private static Activity currentActivity = null;

    private static void DBG(String msg)
    {
        android.util.Log.d(TAG, FILE + msg);
    }
    public static void setActivity(Activity activity)
    {
        DBG("Set context");
        currentActivity = activity;
    }
    public static Activity getActivity()
    {
        if(currentActivity == null)
            DBG("ERROR: CurrentACtivty is not set previously");
        return currentActivity;
    }
    static Context ApplicationContext = null;
}

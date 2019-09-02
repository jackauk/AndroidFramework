package com.android.androidframework.PackageUtils;

import java.lang.ref.WeakReference;
import android.app.Activity;

import com.android.androidframework.FrameworkUtils.SUtils;

public class AndroidUtils {

    private static WeakReference<Activity> s_MainActivityRef = null;

    public static Activity GetActivity()
    {
        return SUtils.getActivity();
    }
    public static void SetActivityRef(Activity activity)
    {
        if(s_MainActivityRef == null)
        {
            s_MainActivityRef = new WeakReference<Activity>(activity);
            SUtils.setActivity(activity);
            //Device.init();
        }
        else
        {}
    }
    public static void onPreNativePause()
    {

    }
    public static void onPause()
    {
//        JNIBridge.NativeOnPause();
    }
    public static void onPostNativePause()
    {

    }
    public static void onPreNativeResume()
    {
        SUtils.setActivity(s_MainActivityRef.get());
    }
    public static void onResume()
    {
//         JNIBridge.NativeOnPause();
    }
    public static void onPostNativeResume()
    {

    }
}

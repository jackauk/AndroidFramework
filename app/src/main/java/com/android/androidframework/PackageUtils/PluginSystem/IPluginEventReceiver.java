package com.android.androidframework.PackageUtils.PluginSystem;

import android.view.KeyEvent;
import android.view.MotionEvent;
import android.content.Intent;
import android.app.Activity;
import android.view.ViewGroup;

public interface IPluginEventReceiver {

    public void onPluginStart(Activity mainActivity, ViewGroup viewGroup);

    public void onPreNativePause();
    public void onPostNativePause();

    public void onPreNativeResume();
    public void onPostNativeResume();

    public boolean onActivityResult(int requestCode, int resultCode, Intent data);
}

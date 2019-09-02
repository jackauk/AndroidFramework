package com.android.androidframework.PackageUtils.Dispatchers;

import android.content.Intent;
import android.app.Activity;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.ViewGroup;

import com.android.androidframework.PackageUtils.AndroidUtils;
import com.android.androidframework.PackageUtils.PluginSystem.PluginEventDispatcher;

public class SignalDispatcher {
    private PluginEventDispatcher m_pPluginEventDispatcher;
    public SignalDispatcher()
    {
        m_pPluginEventDispatcher =new PluginEventDispatcher();
    }
    public void StartDispatcher(Activity activity,ViewGroup viewGroup)
    {
        AndroidUtils.SetActivityRef(activity);
        m_pPluginEventDispatcher.LoadPlugins(activity,viewGroup);
    }
    public void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        m_pPluginEventDispatcher.onActivityResult(requestCode, resultCode, data);
    }
    public void onPause()
    {
        m_pPluginEventDispatcher.onPreNativePause();
        AndroidUtils.onPreNativePause();

        AndroidUtils.onPause();

        m_pPluginEventDispatcher.onPostNativePause();
        AndroidUtils.onPostNativePause();
    }
    public void onResume()
    {
        m_pPluginEventDispatcher.onPreNativeResume();
        AndroidUtils.onPreNativeResume();

        AndroidUtils.onResume();

        m_pPluginEventDispatcher.onPostNativeResume();
        AndroidUtils.onPostNativeResume();
    }
}

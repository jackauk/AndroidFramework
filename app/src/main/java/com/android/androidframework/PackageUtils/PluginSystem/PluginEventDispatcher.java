package com.android.androidframework.PackageUtils.PluginSystem;

import android.content.Intent;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.app.Activity;
import android.view.ViewGroup;
import java.util.ArrayList;

public class PluginEventDispatcher {
    static final String TAG = "JA_LOGGER";
    static final String FILE = "PluginEventDispatcher.java ";

    private ArrayList<IPluginEventReceiver>          m_arrPluginSignalReceiver = null;
    private ArrayList<String>                        m_arrStrLoadedPlugins = null;

    private  void DBG(String msg)
    {
        android.util.Log.d(TAG, FILE + msg);
    }
    private void printLoadedPlugins()
    {
        DBG(" Plugins Loaded: ");
        for (int i = 0; i < m_arrStrLoadedPlugins.size(); i++)
        {
            DBG(m_arrStrLoadedPlugins.get(i));
        }
    }
    public PluginEventDispatcher()
    {
        if (m_arrStrLoadedPlugins == null)
        {
            m_arrPluginSignalReceiver = new ArrayList<IPluginEventReceiver>();
            m_arrStrLoadedPlugins = new ArrayList<String>();
        }
        else
        {
            DBG("ERR: Try to load mutilple dispatcher");
        }
    }
    private void LoadPlugins(Activity mainActivityRef, ViewGroup viewGroup, String[] list)
    {
        for (int i =0; i<list.length; i++)
        {
            String className = list[i];

            Class<?> c = null;
            Object t  = null;

            try
            {
                c = Class.forName(className);
            }
            catch(ClassNotFoundException e)
            {
                DBG("Error: Can not load the class "+className);
                DBG("We will try to load it now "+className);
                c= null;
            }

            if(c == null)
            {
                try
                {
                    c = ClassLoader.getSystemClassLoader().loadClass(className);
                }
                catch(ClassNotFoundException e)
                {
                    DBG("Error: Can not load the class "+className);
                    DBG("Continue to next plugin");
                    continue;
                }
            }

            try
            {
                t = c.newInstance();
            }
            catch (Exception e)
            {
                DBG("Error: Can not instantiate the class "+className+ ". Check Stack trace below");
                e.printStackTrace();
                continue;
            }

            if (t instanceof IPluginEventReceiver)
            {
                IPluginEventReceiver recv  = (IPluginEventReceiver)t;
                RegisterSignalReceiver(recv);
                recv.onPluginStart(mainActivityRef,viewGroup);
                continue;
            }
            else
            {
                DBG("Error: Class "+className+ " is not of type IPluginEventReceiver . Load plugin failed");
                continue;
            }

        }
    }
    public void LoadPlugins(Activity mainActivityRef, ViewGroup viewGroup)
    {
        LoadPlugins(mainActivityRef, viewGroup, PluginListInternal.list);
        LoadPlugins(mainActivityRef, viewGroup, PluginListExternal.list);
        printLoadedPlugins();
    }
    public boolean onActivityResult (int requestCode, int resutlCode, Intent data)
    {
        for (int i = 0; i < m_arrPluginSignalReceiver.size(); i++)
        {
           if(m_arrPluginSignalReceiver.get(i).onActivityResult(requestCode,resutlCode,data))
               return true;
        }
        return false;
    }
    public void onPreNativePause()
    {
        for (int i = 0; i < m_arrPluginSignalReceiver.size(); i++)
        {
            m_arrPluginSignalReceiver.get(i).onPreNativePause();
        }
    }
    public void onPostNativePause()
    {
        for (int i = 0; i < m_arrPluginSignalReceiver.size(); i++)
        {
            m_arrPluginSignalReceiver.get(i).onPostNativePause();
        }
    }
    public void onPreNativeResume()
    {
        for (int i = 0; i < m_arrPluginSignalReceiver.size(); i++)
        {
            m_arrPluginSignalReceiver.get(i).onPreNativeResume();
        }
    }
    public void onPostNativeResume()
    {
        for (int i = 0; i < m_arrPluginSignalReceiver.size(); i++)
        {
            m_arrPluginSignalReceiver.get(i).onPostNativeResume();
        }
    }
    public void RegisterSignalReceiver(IPluginEventReceiver cls)
    {
        String pluginName = cls.getClass().getName();
        if (m_arrStrLoadedPlugins.contains(pluginName)== false)
        {
            m_arrPluginSignalReceiver.add(cls);
            m_arrStrLoadedPlugins.add(pluginName);
        }
        else
        {
            DBG("Class already registerd as a receiver" + pluginName);
            DBG("Check your Plugin list config"  );
        }
    }
}

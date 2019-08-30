//
// Created by hien.nguyenmanh on 8/28/2019.
//

#ifndef NATIVEC_SCOPEGETENV_H
#define NATIVEC_SCOPEGETENV_H

#include <jni.h>
namespace ja_utils
{
    extern JavaVM* GetVM();
    class ScopeGetEnv
    {
        bool m_bThreadAttached;
    public:
        ScopeGetEnv(JNIEnv*& env)
        {
            m_bThreadAttached = false;
            switch (GetVM()->GetEnv((void**)env, JNI_VERSION_1_6 ))
            {
                case JNI_OK:
                    break;
                case JNI_EDETACHED:
                    if( GetVM()->AttachCurrentThread(&env,0) != 0)
                    {
                        throw std::runtime_error("Could not attach current thread");
                    }
                    break;
                case JNI_EVERSION:
                    throw std::runtime_error("Invalid java version");
                    break;
            }
        }
        ~ScopeGetEnv()
        {
            if (m_bThreadAttached)
            {
                (GetEnv())->DetachCurrentThread();
            }
        }
    }
}



#endif //NATIVEC_SCOPEGETENV_H

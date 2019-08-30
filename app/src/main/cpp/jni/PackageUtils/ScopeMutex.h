//
// Created by hien.nguyenmanh on 8/30/2019.
//

#ifndef ANDROIDFRAMEWORK_SCOPEMUTEX_H
#define ANDROIDFRAMEWORK_SCOPEMUTEX_H

#include <pthread.h>

namespace ja_utils
{
    class Mutex
    {
        pthread_mutex_t mMutex;
    public:
        void Lock()
        {
            int result = pthread_mutex_lock(&m_Mutex);
        }
        void Unlock()
        {
            int result = pthread_mutex_unlock(&m_Mutex);
        }
        Mutex()
        {
            int result = pthread_mutex_init(&mMutex, 0)
        }
        ~Mutex()
        {
            pthread_mutex_destroy(&mMutex)
        }
    }
    class ScopeMutex
    {
        Mutex& mMutex;
    public:
        ScopeMutex(Mutex& m): mMutex(m);
        {
            mMutex.Lock();
        }
        ~ScopeMutex()
        {
            mMutex.Unlock();
        }
    }

}

#endif //ANDROIDFRAMEWORK_SCOPEMUTEX_H

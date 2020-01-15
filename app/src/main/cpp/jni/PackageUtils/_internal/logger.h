#ifndef LOGGER_H
#define LOGGER_H

#include <strings.h>
#include <android/log.h>

#define FW_LOGGER_TAG "FW_LOGGER"

#ifdef NDEBUG
    	#define LOG_INFO(...)
    	#define LOG_ERROR(...)
    	#define LOG_DBG(...)
#else
	#define LOG_INFO(...) __android_log_print(ANDROID_LOG_INFO, FW_LOGGER_TAG, __VA_ARGS__)
	#define LOG_ERROR(...) __android_log_print(ANDROID_LOG_ERROR, FW_LOGGER_TAG, __VA_ARGS__)
	#define LOG_DBG(...) __android_log_print(ANDROID_LOG_INFO, FW_LOGGER_TAG, __VA_ARGS__)
#endif


#endif // LOGGER_H
/*
* Author: Chris Campbell - www.iforce2d.net
*
* See usage details at http://www.iforce2d.net/cc2dxres/screenlog
*
* This software is provided 'as-is', without any express or implied warranty.
* In no event will the authors be held liable for any damages arising from
* the use of this software. Permission is granted to anyone to use this software
* for any purpose, including commercial applications, and to alter it and
* redistribute it freely.
*
*/

#ifndef SCREEN_LOG_H
#define SCREEN_LOG_H

#include <string>
#include <vector>
#include "cocos2d.h"

#define LL_FATAL    0x01
#define LL_ERROR    0x02
#define LL_WARNING  0x04
#define LL_INFO     0x08
#define LL_DEBUG    0x10
#define LL_TRACE    0x20

#if defined WIN32
#include <Windows.h>
typedef HANDLE pthread_mutex_t;
typedef int pthread_mutexattr_t; // not used. win32 muteces are recursive by default
static const int PTHREAD_MUTEX_RECURSIVE = 0;

static void pthread_mutex_init(pthread_mutex_t* mtx, const pthread_mutexattr_t*)
{
	*mtx = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);
}

static void pthread_mutex_destroy(pthread_mutex_t* mtx)
{
	CloseHandle(*mtx);
}

static void pthread_mutex_lock(pthread_mutex_t* mtx)
{
	WaitForSingleObject(
		*mtx,    // handle to mutex
		INFINITE);  // no time-out interval
}

static void pthread_mutex_unlock(pthread_mutex_t* mtx)
{
	ReleaseMutex(*mtx);
}

static void pthread_mutexattr_init(pthread_mutexattr_t*)
{
	// nothing to do
}

static void pthread_mutexattr_settype(pthread_mutexattr_t*, int)
{
	// nothing to do
}
#endif

//////////////////////////////////////////////////////////////////////

class screenLogMessage {
    friend class ScreenLog;
private:
    class ScreenLog* m_layer;
    int m_level;
    std::string m_text;
    float m_timestamp;
    cocos2d::CCLabelTTF* m_label;
    bool m_dirty;

private:
    screenLogMessage(ScreenLog* layer) {
        m_layer = layer;
        m_label = NULL;
        m_level = 0;
        m_timestamp = 0;
        m_dirty = true;
    }
    virtual ~screenLogMessage() { }

    void setLabelText(std::string msg);
    void createLabel();
    bool checkLabel();
};

//////////////////////////////////////////////////////////////////////

class ScreenLog : public cocos2d::CCLayer
{
    friend class screenLogMessage;
private:
    std::string m_fontFile;
    int m_level;
    float m_timeout;
    std::vector<screenLogMessage*> m_messages;
    pthread_mutex_t m_contentMutex;

public:

    ScreenLog();
    ~ScreenLog();

    void setFontFile(std::string file);
    void setLevelMask(int level);
    void setTimeoutSeconds(float seconds);
    void attachToScene(cocos2d::CCScene* scene);

    screenLogMessage* log(int level, const char* msg, ...);
    void setMessageText(screenLogMessage* slm, const char *p_str, ...);

    void update(float dt);
    void moveLabelsUp(int maxIndex);
    void clearEntries();
};

extern ScreenLog* g_screenLog;

//////////////////////////////////////////////////////////////////////

class ScopeLock {
public:
    pthread_mutex_t* m_mutex;
    ScopeLock(pthread_mutex_t* m) {
        m_mutex = m;
        pthread_mutex_lock(m_mutex);
    }
    ~ScopeLock() {
        pthread_mutex_unlock(m_mutex);
    }
};

//////////////////////////////////////////////////////////////////////

class ScopeLog {
public:
    std::string m_functionName;
    ScopeLog(std::string fn) {
        m_functionName = fn;
        g_screenLog->log(LL_TRACE, "Entered %s", m_functionName.c_str());
    }
    ~ScopeLog() {
        g_screenLog->log(LL_TRACE, "Exiting %s", m_functionName.c_str());
    }
};

//////////////////////////////////////////////////////////////////////

#endif

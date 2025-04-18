#include "Zuma_Prefix.pch"

#include "WorkerThread.h"

#ifdef _WIN32
#include <windows.h>
#include <process.h>
#else
#error WorkerThread is unimplemented on non-win32 platforms.
#endif

using namespace Sexy;

WorkerThread::WorkerThread() //11-19
{
	mTask = NULL;
	mTaskArg = NULL;
	mStopped = false;
	mSignalEvent = CreateEventA(0, FALSE, FALSE, NULL); //C++
	mDoneEvent = CreateEventA(0, FALSE, FALSE, NULL); //C++

	_beginthread((void(*)(void*)) StaticThreadProc, 0, this); //C++
}

WorkerThread::~WorkerThread() //24-32
{
	if (mTask)
	{
		while (mTask)
			WaitForSingleObject(mDoneEvent, 1000);
	}
	mStopped = true;
	SetEvent(mSignalEvent);
	WaitForSingleObject(mDoneEvent, 5000);
	CloseHandle(mSignalEvent);
	CloseHandle(mDoneEvent);
}

void WorkerThread::StaticThreadProc(HANDLE* that) //37-42 | C++ only
{
	//Some comment

	SetThreadPriority(GetCurrentThread(), -2);
	//ThreadProc; //?
}

void WorkerThread::ThreadProc() //47-63
{
	WaitForSingleObject(mSignalEvent, 1000);
	while (!mStopped)
	{
		if (mTask)
		{
			mTask(mTaskArg);
			mTask = 0;
			SetEvent(mDoneEvent);
		}
		WaitForSingleObject(mSignalEvent, 1000);
	}
	SetEvent(mDoneEvent);
}

void WorkerThread::WaitForTask() //68-73
{
	while (mTask)
	{
		WaitForSingleObject(mDoneEvent, 1000);
	}

	ResetEvent(mDoneEvent);
}

void WorkerThread::DoTask(void (*theTask)(void*), void* theTaskArg) //78-83
{
	while (mTask)
		WaitForSingleObject(mDoneEvent, 1000);

	ResetEvent(mDoneEvent);

	mTask = theTask;
	mTaskArg = theTaskArg;

	SetEvent(mSignalEvent);
}
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
	mStopped = false;
	mSignalEvent = CreateEventA(0, FALSE, FALSE, NULL); //C++
	mDoneEvent = CreateEventA(0, FALSE, FALSE, NULL); //C++

	_beginthread((void(*)(void*)) StaticThreadProc, 0, this); //C++
}

WorkerThread::~WorkerThread()
{
	//Needed?
	
	//if (mTask)
	//{
	//	while (mTask)
	//		WaitForSingleObject(mDoneEvent, 1000);
	//}
	//ResetEvent(mDoneEvent);
	//mStopped = true;
	//SetEvent(mSignalEvent);
	//WaitForSingleObject(mDoneEvent, 5000);
	//CloseHandle(mSignalEvent);
	//CloseHandle(mDoneEvent);
}

void WorkerThread::WaitForTask()
{
	while (mTask)
		WaitForSingleObject(mDoneEvent, 1000);

	ResetEvent(mDoneEvent);
}

void WorkerThread::DoTask(void (*theTask)(void*), void* theTaskArg)
{
	WaitForTask();

	mTask = theTask;
	mTaskArg = theTaskArg;

	SetEvent(mSignalEvent);
}

void WorkerThread::StaticThreadProc(WorkerThread* that)
{
	HANDLE ct = GetCurrentThread();
	SetThreadPriority(ct, THREAD_PRIORITY_LOWEST);
	WaitForSingleObject(that->mSignalEvent, 1000);
	while (!that->mStopped)
	{
		if (that->mTask) {
			that->mTask(that->mTaskArg);
			that->mTask = NULL;

			SetEvent(that->mDoneEvent);
		}

		WaitForSingleObject(that->mSignalEvent, 1000);
	}

	SetEvent(that->mSignalEvent);
}
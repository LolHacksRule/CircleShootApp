#ifndef __SEXY_WORKER_THREAD_H__
#define __SEXY_WORKER_THREAD_H__

#include "CircleCommon.h"

#include <vector>
#include <list>

#include <windows.h>

namespace Sexy
{
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	class WorkerThread
	{
	public:
		HANDLE mSignalEvent;
		HANDLE mDoneEvent;
		void (*mTask)(void *);
		void *mTaskArg;
		bool mStopped;
	public:
		WorkerThread();

		virtual ~WorkerThread();

		void DoTask(void (*theTask)(void*), void* theTaskArg);
		void WaitForTask();

		//For the O&D fork, only keeping for reference
		// typedef ? conditionT
		//ClearSignal(conditionT);
		//Lock();
		//Signal(conditionT);
		//ThreadSafePrintf(const char*);
		//Unlock();
		//Wait(conditionT, int);

		static void StaticThreadProc(WorkerThread* that);
	};
};

#endif
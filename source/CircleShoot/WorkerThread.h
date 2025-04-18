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
	protected:
		HANDLE mSignalEvent;
		HANDLE mDoneEvent;
		void (*mTask)(void *);
		void *mTaskArg;
		bool mStopped;
		void ThreadProc();
	public:

		WorkerThread();

		virtual ~WorkerThread();

		void DoTask(void (*theTask)(void*), void* theTaskArg);
		void WaitForTask();
		bool IsProcessingTask();

		//For the O&D fork, only keeping for reference
		// typedef ? conditionT
		//ClearSignal(conditionT);
		//Lock();
		//Signal(conditionT);
		//ThreadSafePrintf(const char*);
		//Unlock();
		//Wait(conditionT, int);

	protected:
		static void StaticThreadProc(HANDLE* that);
	};
};

#endif
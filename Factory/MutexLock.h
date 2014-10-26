/**************************************************************
	> file: MutexLock.h
	> by: zkw
	> description:
 **************************************************************/
#ifndef MUTEX_LOCK_H_
#define MUTEX_LOCK_H_

#include <pthread.h>
#include "NonCopyable.h"

class MutexLock : private NonCopyable
{
	public:
		MutexLock();
		~MutexLock();
		void lock();
		void unlock();
		pthread_mutex_t *getLockPtr();

	private:
		pthread_mutex_t mutex_lock_;
};

#endif //MUTEX_LOCK_H_

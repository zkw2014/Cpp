/**************************************************************
	> file: MutexLock.h
	> by: zkw
	> description:
 **************************************************************/
#ifndef MUTEX_LOCK_H_
#define MUTEX_LOCK_H_

#include <pthread.h>

class MutexLock
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

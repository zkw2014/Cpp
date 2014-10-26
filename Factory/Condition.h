/**************************************************************
	> file: Condition.h
	> by: zkw
	> description:
 **************************************************************/
#ifndef CONDITION_H_
#define CONDITION_H_

#include <pthread.h>
#include "NonCopyable.h"
class MutexLock; //因为只用到了引用

class Condition : private NonCopyable
{
	public:
		Condition(MutexLock &mutex_lock);
		~Condition();
		void wait();
		void notify();
		void notifyAll();

	private:
		pthread_cond_t cond_lock_;
		MutexLock &mutex_lock_;
};

#endif //CONDITION_H_

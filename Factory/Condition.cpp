/**************************************************************
	> file: Condition.cpp
	> by: zkw
	> description:
 **************************************************************/
#include <stdexcept>
#include "Condition.h"
#include "MutexLock.h"
using namespace std;

Condition::Condition(MutexLock &mutex_lock)
	:mutex_lock_(mutex_lock)
{
	if (pthread_cond_init(&cond_lock_, NULL) != 0)
		throw runtime_error("pthread_cond_init");
}

Condition::~Condition()
{
	if (pthread_cond_destroy(&cond_lock_) != 0)
		throw runtime_error("pthread_cond_destroy");
}

void Condition::wait()
{
	pthread_mutex_t *ptr = mutex_lock_.getLockPtr();
	if (pthread_cond_wait(&cond_lock_, ptr) != 0)
		throw runtime_error("pthread_cond_wait");
}

void Condition::notify()
{
	if (pthread_cond_signal(&cond_lock_) != 0)
		throw runtime_error("pthread_cond_signal");
}

void Condition::notifyAll()
{
	if (pthread_cond_broadcast(&cond_lock_) != 0)
		throw runtime_error("pthread_cond_broadcast");
}

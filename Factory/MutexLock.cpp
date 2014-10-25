/**************************************************************
	> file: MutexLock.cpp
	> by: zkw
	> description:
 **************************************************************/
#include "MutexLock.h" 
#include <stdexcept>
using namespace std;

MutexLock::MutexLock()
{
	if (pthread_mutex_init(&mutex_lock_, NULL) != 0)
		throw runtime_error("pthread_mutex_init");
}

MutexLock::~MutexLock()
{
	if (pthread_mutex_destroy(&mutex_lock_) != 0)
		throw runtime_error("pthread_mutex_destroy");
}

void MutexLock::lock()
{
	if (pthread_mutex_lock(&mutex_lock_) != 0)
		throw runtime_error("pthread_mutex_lock");
}

void MutexLock::unlock()
{
	if (pthread_mutex_unlock(&mutex_lock_) != 0)
		throw runtime_error("pthread_mutex_unlock");
}


pthread_mutex_t *MutexLock::getLockPtr()
{
	return &mutex_lock_;
}


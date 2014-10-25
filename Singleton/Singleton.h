/**************************************************************
	> file: Singleton.h
	> by: zkw
	> description:
 **************************************************************/
#ifndef SINGLETON_H_
#define SINGLETON_H_
#include "MutexLock.h"

class Singleton
{
	public:
		static Singleton *getInstance();
		~Singleton();

	private:
		Singleton();
		Singleton(const Singleton &other);
		Singleton &operator=(const Singleton &other);
		
		static Singleton *p_instance;
		static MutexLock mutex_lock_;
};

#endif //SINGLETON_H_

/**************************************************************
	> file: Singleton.cpp
	> by: zkw
	> description:
 **************************************************************/
#include <iostream>
#include "Singleton.h"
using namespace std;

Singleton *Singleton::p_instance = NULL;
MutexLock Singleton::mutex_lock_;

Singleton::Singleton()
{
	cout << "Singleton()" << endl;
}

Singleton *Singleton::getInstance()
{
	mutex_lock_.lock();
	if (NULL == p_instance) {
		p_instance = new Singleton;
	}
	mutex_lock_.unlock();

	return p_instance;
}



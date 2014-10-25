/**************************************************************
	> file: test.cpp
	> by: zkw
	> description:
 **************************************************************/
#include <iostream>
#include <vector>
#include <pthread.h>
#include "Singleton.h"
using namespace std;

void *threadFunc(void *arg)
{
	Singleton *p = Singleton::getInstance();
	cout << p << endl;

	return NULL;
}

int main(void)
{
	vector<pthread_t> vec(50);

	vector<pthread_t>::iterator it = vec.begin();
	for (; it != vec.end(); ++it) {
		pthread_create(&*it, NULL, threadFunc, NULL);
	}

	it = vec.begin();
	for (; it != vec.end(); ++it) {
		pthread_join(*it, NULL);
	}	

	return 0;
}

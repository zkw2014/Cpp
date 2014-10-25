/**************************************************************
	> file: Singleton.cpp
	> by: zkw
	> description:
 **************************************************************/
#include "Singleton.h"
#include <iostream>
using namespace std;

Singleton *Singleton::p_instance = NULL;

Singleton::Singleton()
{
	cout << "Singleton()" << endl;
}

Singleton *Singleton::getInstance()
{
	if (NULL == p_instance) {
		p_instance = new Singleton;
	}
	return p_instance;
}



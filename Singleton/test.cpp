/**************************************************************
	> file: main.cpp
	> by: zkw
	> description:
 **************************************************************/
#include <iostream>
#include "Singleton.h"
using namespace std;

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	Singleton *p3 = Singleton::getInstance();

	cout << p1 << " " << p2 << " " << p3 << endl;
	
	return 0;
}

/************************************************************************
    > File: main.cpp
    > By: zkw
    > Description: 智能指针的表现像一个指针，并且智能指针的传入参数需是堆地址
 ************************************************************************/

#include <iostream>
#include "Student.h"
#include "SmartPtr.h"
using namespace std;

int main(void)
{
	SmartPtr sp(new Student(10, "zkw")); //sp在栈上，而Student在堆上
	sp->print();

	sp.resetPtr(new Student(20, "xy")); //resetPtr会释放原先的堆内存，
	(*sp).print();
	
	cout << "before return......" << endl;
	//回收智能指针的栈内存时，会调用智能指针的析构函数，从而释放在堆上存放的Student内存
	return 0;
}

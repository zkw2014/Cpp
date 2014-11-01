/************************************************************************
    > File: SmartPtr.cpp
    > By: zkw
    > Description: 
 ************************************************************************/

#include <iostream>
#include "SmartPtr.h"
#include "Student.h"
using namespace std;

SmartPtr::SmartPtr():
	sb_(NULL)
{
}

SmartPtr::SmartPtr(Student *sb):
	sb_(sb)
{
}

SmartPtr::~SmartPtr()
{
	delete sb_; //释放在堆上存放的Student内存
}

Student *SmartPtr::operator->()
{
	return sb_;
}

const Student *SmartPtr::operator->() const
{
	return sb_;
}

Student &SmartPtr::operator*()
{
	return *sb_;
}

const Student &SmartPtr::operator*() const
{
	return *sb_;
}

void SmartPtr::resetPtr(Student *sb)
{
	if (sb_ != sb) {
		delete sb_; //先释放原先的Student堆内存
		sb_ = sb;
	}
}

const Student *SmartPtr::getPtr() const
{
	return sb_;
}

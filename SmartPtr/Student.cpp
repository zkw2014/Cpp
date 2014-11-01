/************************************************************************
    > File: Student.cpp
    > By: zkw
    > Description: 
 ************************************************************************/

#include <iostream>
#include "Student.h"
using namespace std;

Student::Student(int id, const std::string &name):
	id_(id), name_(name)
{
	cout << "create Student: id_ = " << id_ << " name_ = " << name_ << endl;
}

Student::~Student()
{
	cout << "destroy Student: id_ = " << id_ << " name_ = " << name_ << endl;
}

void Student::print() const
{
	cout << "print: id_ = " << id_ << " name_ = " << name_ << endl;
}

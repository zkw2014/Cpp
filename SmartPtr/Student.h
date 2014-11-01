/************************************************************************
    > File: Student.h
    > By: zkw
    > Description: 
 ************************************************************************/

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student {
public:
	Student(int id, const std::string &name);
	~Student();
	void print() const;

private:
	int id_;
	std::string name_;
};

#endif //STUDENT_H_

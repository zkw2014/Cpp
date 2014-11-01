/************************************************************************
    > File: SmartPtr.h
    > By: zkw
    > Description: 
 ************************************************************************/

#ifndef SMART_PTR_H_
#define SMART_PTR_H_

class Student;

class SmartPtr {
public:
	SmartPtr();
	SmartPtr(Student *sb); //有个疑问，如果Student对象已经被析构了，会发生错误
	~SmartPtr();

	Student *operator->();
	const Student *operator->() const;

	Student &operator*();
	const Student &operator*() const;

	void resetPtr(Student *sb);
	const Student *getPtr() const;

private:
	SmartPtr(const SmartPtr &other);
	SmartPtr &operator=(const SmartPtr &other);

	Student *sb_;
};

#endif //SMART_PTR_H_

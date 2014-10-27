/************************************************************************
  > File: Buffer.cpp
  > By: zkw
  > Description: 
 ************************************************************************/

#include <iostream>
#include "Buffer.h"
using namespace std;

Buffer::Buffer(size_t capacity):
	hasTask_(lock_), hasSpace_(lock_), capacity_(capacity), size_(0)
{
}

void Buffer::produce(int data)
{
	lock_.lock();

	//while的使用很经典，保证线程跳出while语句时，一定满足了两个条件：
	//1）要重新拿到了锁； 2）队列不满。
	while (isFull()) {
		hasSpace_.wait();
	}
	if (isEmpty()) {
		queue_.push(data);
		hasTask_.notify();
	} else {
		queue_.push(data);
	}
	++size_;
	cout << "produce: " << data << endl;

	lock_.unlock();
}

int Buffer::consume()
{
	lock_.lock();

	while (isEmpty())
		hasTask_.wait();
	int temp = queue_.top();
	if (isFull()) {
		queue_.pop();
		hasSpace_.notify();
	} else {
		queue_.pop();
	}
	--size_;
	cout << "consume: " << temp << endl;

	lock_.unlock();
	return temp;
}

size_t Buffer::getCapacity() const
{
	return capacity_;
}

size_t Buffer::getSize() const
{
	return size_;
}

bool Buffer::isEmpty() const
{
	return (0 == size_);
}

bool Buffer::isFull() const
{
	return (size_ == capacity_);
}

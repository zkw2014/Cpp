/************************************************************************
    > File: Buffer.h
    > By: zkw
    > Description: 将queue,mutexlock和条件锁封装成一个buffer类,从此多线程使用buffer，不需要再考虑同步互斥问题。
 ************************************************************************/

#ifndef BUFFER_H_
#define BUFFER_H_

#include "Condition.h"
#include "MutexLock.h"
#include "Queue.h"

class Buffer : private NonCopyable
{
	public:
		Buffer(size_t capacity);
		void produce(int data);
		int consume();
		size_t getCapacity() const;
		size_t getSize() const;
		bool isEmpty() const;
		bool isFull() const;

	private:
		Queue queue_;
		MutexLock lock_;
		Condition hasTask_;
		Condition hasSpace_;
		size_t capacity_;
		size_t size_;
};

#endif //BUFFER_H_


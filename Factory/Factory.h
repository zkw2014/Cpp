/************************************************************************
    > File: Factory.h
    > By: zkw
    > Description: 
 ************************************************************************/

#ifndef FACTORY_H_
#define FACTORY_H_

#include <vector>
#include <cstddef>
#include "Thread.h"
#include "Buffer.h"

class Factory : private NonCopyable
{
	public:
		typedef void *(*FUNC)(void *);

		Factory(int producer_nums, FUNC producer_func, int consumer_nums, FUNC consumer_func, size_t buffer_capacity);
		void start();

	private:
		Buffer buffer_;
		std::vector<Thread> producers_;
		std::vector<Thread> consumers_;
};

#endif //FACTORY_H_


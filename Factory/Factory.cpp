/************************************************************************
  > File: Factory.cpp
  > By: zkw
  > Description: 
 ************************************************************************/

#include "Factory.h"
using namespace std;

Factory::Factory(int producer_nums, FUNC producer_func, int consumer_nums, FUNC consumer_func, size_t buffer_capacity):
	buffer_(buffer_capacity),
	producers_(producer_nums, Thread(producer_func, buffer_)),
	consumers_(consumer_nums, Thread(consumer_func, buffer_))
{}

void Factory::start()
{
	vector<Thread>::iterator it = producers_.begin();
	for (; it != producers_.end(); ++it)
		it->start();

	it = consumers_.begin();
	for (; it != consumers_.end(); ++it)
		it->start();

	it = producers_.begin();
	for (; it != producers_.end(); ++it)
		it->join();

	it = consumers_.begin();
	for (; it != consumers_.end(); ++it)
		it->join();
}


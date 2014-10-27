/************************************************************************
  > File: test_Factory.cpp
  > By: zkw
  > Description: 
 ************************************************************************/

#include <iostream>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "Factory.h"
using namespace std;

void *producer(void *arg)
{
	srand(time(NULL));
	Buffer *buffer = static_cast<Buffer *>(arg);
	while (1) {
		int data = rand()%100;
		buffer->produce(data);
		sleep(1);
	}

	return NULL;
}

void *consumer(void *arg)
{
	Buffer *buffer = static_cast<Buffer *>(arg);
	while (1) {
		buffer->consume();
		sleep(1);
	}

	return NULL;
}

int main(void)
{
	size_t producer_nums = 2;
	size_t consumer_nums = 10;
	size_t buffer_capacity = 5;

	Factory f1(producer_nums, producer, consumer_nums, consumer, buffer_capacity);
	f1.start();

	return 0;
}



/************************************************************************
    > File: Queue.cpp
    > By: zkw
    > Description: 
 ************************************************************************/

#include "Queue.h"
#include <stdexcept>
#include <assert.h>
using namespace std;

Queue::Queue()
	:head_(NULL), tail_(NULL), size_(0)
{
}

Queue::~Queue()
{
	if (size_ > 0) {
		clear();
	}
}

int Queue::top() const
{
	assert(size_ > 0);
	return head_->data_;
}

void Queue::push(int data)
{
	NodePtr temp = new Node(data);
	if (NULL == temp)
		throw runtime_error("new Node");
	if (isEmpty()) {
		head_ = tail_ = temp;
	} else {
		tail_->next_ = temp;
		tail_ = temp;
	}
	++size_;
}

void Queue::pop()
{
	assert(size_ >= 1);

	if (1 == size_) {
		delete head_;
		head_ = tail_ = NULL;
	} else {
		NodePtr temp = head_;
		head_ = head_->next_;
		delete temp;
	}
	--size_;
}

void Queue::clear()
{
	while (false == isEmpty())
		pop();
}

bool Queue::isEmpty() const
{
	return size_ == 0;
}

size_t Queue::getSize() const
{
	return size_;
}



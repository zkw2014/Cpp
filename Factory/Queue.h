/************************************************************************
    > File: Queue.h
    > By: zkw
    > Description: 
 ************************************************************************/

#ifndef QUEUE_H_
#define QUEUE_H_
#include <cstddef>

class Node
{
	public:
		friend class Queue;
	
	private:
		Node() : data_(0), next_(NULL) {} //只有友元类可以构造节点
		Node(int data) : data_(data), next_(NULL) {}

		int data_;
		Node *next_;
};

typedef Node *NodePtr;

class Queue
{
	public:
		Queue();
		~Queue();
		int top() const;
		void push(int data);
		void pop();
		void clear();
		bool isEmpty() const;
		size_t getSize() const;

	private:
		NodePtr head_;
		NodePtr tail_;
		size_t size_;
};

#endif //QUEUE_H_


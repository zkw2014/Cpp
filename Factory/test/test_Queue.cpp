/************************************************************************
    > File: test_Queue.cpp
    > By: zkw
    > Description: 
 ************************************************************************/

#include <iostream>
#include "Queue.h"
using namespace std;

int main(void)
{
	Queue q1;
	q1.push(10);
	q1.push(20);
	q1.push(30);
	cout << "size:" << q1.getSize() << endl;
	
	cout << q1.top() << endl;
	q1.pop();
	cout << q1.top() << endl;

	q1.clear();
	cout << "size:" << q1.getSize() << endl;
	if (q1.isEmpty() == true)
		cout << "Queue is empty" << endl;

}



/************************************************************************
    > File: test_Buffer.cpp
    > By: zkw
    > Description: 
 ************************************************************************/

#include <iostream>
#include "Buffer.h"
using namespace std;

int main(void)
{
	Buffer buffer(10); //10, 0
	cout << "capacity..." << buffer.getCapacity() << endl;
	cout << "size..." << buffer.getSize() << endl;

	buffer.produce(1);
	buffer.produce(2); //10, 2
	cout << "capacity..." << buffer.getCapacity() << endl;
	cout << "size..." << buffer.getSize() << endl;

	buffer.consume();
	buffer.consume();
	cout << "capacity..." << buffer.getCapacity() << endl;
	cout << "size..." << buffer.getSize() << endl;

	return 0;
}



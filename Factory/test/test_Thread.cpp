/************************************************************************
    > File: test_Thread.cpp
    > By: zkw
    > Description: 
 ************************************************************************/

#include <iostream>
#include <unistd.h>
#include "Thread.h"
using namespace std;

//用户逻辑交给用户来编写
void *func(void *arg)
{
	while(1) {
		cout << "hello" << endl;
		sleep(1);
	}
	
	return NULL;
}

int main(void)
{
	Thread t1(func); //定义一个运行用户逻辑（func)的线程
	t1.start(); //线程开始运行
	t1.join(); //成功执行后，表示线程运行结束

	return 0;
}



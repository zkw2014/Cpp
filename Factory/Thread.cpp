/**************************************************************
	> file: Thread.cpp
	> by: zkw
	> description:
 **************************************************************/

#include <stdexcept>
#include "Thread.h"
using namespace std;

Thread::Thread(FUNC callback, Buffer &buffer)
	:tid_(-1), is_started_(false), callback_(callback), buffer_(buffer)
{
}

Thread::~Thread()
{
	//析构后，不会再有对象去调用join，所以要把子线程设置成detach状态
	if (true == is_started_) {
		if (pthread_detach(tid_) != 0)
			throw runtime_error("pthread_detach");
	}
}

void Thread::join()
{
	if (pthread_join(tid_, NULL) != 0)
		throw runtime_error("pthread_join");
	is_started_ = false; //表示子线程结束了
}

void Thread::start()
{
	if (pthread_create(&tid_, NULL, callback_, &buffer_) != 0)
		throw runtime_error("pthread_create");
	is_started_ = true;
}

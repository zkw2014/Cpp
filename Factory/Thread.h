/**************************************************************
	> file: Thread.h
	> by: zkw
	> description:
 **************************************************************/
#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>
#include "NonCopyable.h"

class Buffer;

class Thread
{
	public:
		typedef void *(*FUNC)(void *arg);

		Thread(FUNC callback, Buffer &buffer);
		~Thread();
		void join();
		void start();

	private:
		pthread_t tid_; 
		bool is_started_; //用来表示创建的新线程的运行状态
		FUNC callback_;
		Buffer &buffer_;
};

#endif //THREAD_H_

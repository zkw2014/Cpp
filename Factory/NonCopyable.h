/************************************************************************
    > File: NonCopyable.h
    > By: zkw
    > Description: 用来做其它类的基类，变相禁掉其它类的拷贝语义
 ************************************************************************/

#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_

class NonCopyable
{
	public:
		NonCopyable() {}

	private:
		NonCopyable(const NonCopyable &other);
		NonCopyable &operator=(const NonCopyable &other);
};

#endif //NONCOPYABLE_H_


/************************************************************************
    > File: String.cpp
    > By: zkw
    > Description: 实现简易string类 
 ************************************************************************/

#include <iostream>
#include <assert.h>
#include <string.h>
#include "String.h"
using namespace std;

String::String():
	str_(new char[1]) //目的是方便统一delete
{
	str_[1] = '\0';
}

String::String(const char *other) //注意要深拷贝
{
	assert(NULL != other);
	str_ = new char[strlen(other) + 1];
	strcpy(str_, other);
}

String::String(const String &other)
{
	str_ = new char[other.size() + 1];
	strcpy(str_, other.str_);
}

String::~String()
{
	delete [] str_;
	str_ = NULL;
}

String &String::operator=(const String &other) //注意考虑自身赋值问题
{
	if (*this == other)
		return *this;
	delete [] str_;
	str_ = new char[other.size() + 1];
	strcpy(str_, other.str_);
	return *this;
}

String &String::operator=(const char *other)
{
	*this = String(other);
	return *this;
}

String &String::operator+=(const String &other)
{
	char *p = new char[strlen(str_) + strlen(other.str_) + 1];
	strcpy(p, str_);
	strcat(p, other.str_);
	delete [] str_;
	str_ = p;
	
	return *this;
}

String &String::operator+=(const char *other)
{
	 return *this += String(other);
}

char &String::operator[](std::size_t ix)
{
	assert ( (ix >= 0) && (ix <= size() -1)); //注意数组下标越界问题
	return str_[ix];
}

const char &String::operator[](std::size_t ix) const
{
	assert ( (ix >= 0) && (ix <= size() -1));
	return str_[ix];
}

std::size_t String::size() const
{
	return strlen(str_);
}

const char *String::c_str() const //返回值得是const
{
	return str_;
}

void String::debug() const
{
	cout << str_ << endl;
}

String operator+(const String &str1, const String &str2) //+调用+=
{
	String temp(str1);
	return temp += str2;
}

String operator+(const char *str1, const String &str2)
{
	return String(str1) + str2;
}

String operator+(const String &str1, const char *str2)
{
	return str1 + String(str2);
}

bool operator==(const String &str1, const String &str2)
{
	return strcmp(str1.str_, str2.str_) == 0;
}

bool operator!=(const String &str1, const String &str2)
{
	return !(str1 == str2);
}

bool operator<(const String &str1, const String &str2)
{
	return strcmp(str1.str_, str2.str_) < 0;
}

bool operator<=(const String &str1, const String &str2)
{
	return !(str1 > str2);
}

bool operator>(const String &str1, const String &str2)
{
	return str2 < str1;
}

bool operator>=(const String &str1, const String &str2)
{
	return !(str1 < str2);
}

std::ostream &operator<<(std::ostream &os, const String &str) //注意把换行的权利留给外部
{
	os << str.str_;
	return os;
}

std::istream &operator>>(std::istream &is, String &str) //注意判断流为bad的情况
{
	char temp[1024] = {'\0'};
	is >> temp;
	if (!is)
		return is;
	str = temp;

	return is;
}

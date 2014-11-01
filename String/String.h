/************************************************************************
    > File: String.h
    > By: zkw
    > Description: 
 ************************************************************************/

#ifndef STRING_H_
#define STRING_H_

#include <cstddef>
class ostream;
class istream;

class String
{
	public:
		String();
		String(const char *other);
		String(const String &other);
		~String();

		String &operator=(const String &other); //注意考虑自身赋值问题
		String &operator=(const char *other);
		String &operator+=(const String &other);
		String &operator+=(const char *other);
		char &operator[](std::size_t ix);
		const char &operator[](std::size_t ix) const;

		std::size_t size() const;
		const char *c_str() const;//返回的是一个临时值,觉得返回值应该可以不加const
		void debug() const; //注意要把换行的权利交给外部

		friend String operator+(const String &str1, const String &str2); //+调用+=
		friend String operator+(const char *str1, const String &str2);
		friend String operator+(const String &str1, const char *str2);
		
		friend bool operator==(const String &str1, const String &str2);
		friend bool operator!=(const String &str1, const String &str2);
		friend bool operator<(const String &str1, const String &str2);
		friend bool operator<=(const String &str1, const String &str2);
		friend bool operator>(const String &str1, const String &str2);
		friend bool operator>=(const String &str1, const String &str2);

		friend std::ostream &operator<<(std::ostream &os, const String &str);
		friend std::istream &operator>>(std::istream &is, String &str); //注意判断流为bad的情况

	private:
		char *str_;
};

#endif //STRING_H_

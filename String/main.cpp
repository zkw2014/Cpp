/************************************************************************
    > File: main.cpp
    > By: zkw
    > Description: 
 ************************************************************************/

#include <iostream>
#include "String.h"
using namespace std;

int main(void)
{
	String s1;
	cout << "s1 = " << s1 << endl; //空串
	cout << "s1.size = " << s1.size() << endl; //0

	String s2("hello");
	cout << "s2 = " << s2 << endl; //"hello"
	cout << "s2.size = " << s2.size() << endl; //5
	cout << "s2[0]= " << s2[0] << endl << "s2[4]= " << s2[4] << endl; //'h', 'o'

	String s3(s2);
	cout << "s3 = " << s3 << endl; //"hello"
	s3 = s1;
	cout << "s3 = " << s3 << endl; // 空串
	cout << "s3.size = " << s3.size() << endl; //0

	s3 += "world";
	cout << "s3 = " << s3 << endl; // "world"
	cout << s3.c_str() << endl; //"world"
	s3.debug(); //"world"

	String s4 = s2 + s3;
	cout << "s4 = " << s4 << endl; // "helloworld"

	if (s2 == s4)
		cout << "s2 == s4" << endl;
	else if (s2 < s4)
		cout << "s2 < s4" << endl; //s2 < s4
	else if (s2 > s4)
		cout << "s2 > s4" << endl;

	String s5;
	cin >> s5;
	cout << "s5= " << s5 << endl; // s5 = zkw

	return 0;
}



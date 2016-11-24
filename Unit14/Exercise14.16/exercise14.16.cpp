#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <utility>
#include "String.h"

using std::allocator;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

allocator<char> String::alloc = allocator<char>();

int main()
{
	String s1("Hello");
	String s2("World");
	String s3("Hello");
	cout << s1 << " " << s2 << " " << s3 << endl;

	if(s1 == s2)
	{
		cout << "s1 == s2" << endl;
	}

	if(s2 == s3)
	{
		cout << "s2 == s3" << endl;
	}

	if(s1 == s3)
	{
		cout << "s1 == s3" << endl;
	}

	if(s1 != s2)
	{
		cout << "s1 != s2" << endl;
	}

	if(s2 != s3)
	{
		cout << "s2 != s3" << endl;
	}

	if(s1 != s3)
	{
		cout << "s1 != s3" << endl;
	}
}
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include "StrBlob.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::initializer_list;

int main(int argc, char const *argv[])
{
	StrBlob b1;
	b1.push_back("b1.str1");
	StrBlob b2{"b2.str1"};
	cout << "b1.front() " << b1.front() << endl;
	cout << "b2.front() " << b2.front() << endl;
	// cout　<<　"b1.front() = " << b1.front() << endl;
	// cout　<<　"b2.front() = " << b2.front() << endl;
	return 0;
}
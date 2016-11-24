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
	// String s2("Yuan");
	// String s2("Meng");
	vector<String> vec;
	vec.reserve(4);
	cout << endl << endl;
	cout << "vec.push_back(s1): ";
	vec.push_back(s1);
	cout << endl << endl;

	cout << "vec.push_back(std::move(s2)): ";
	vec.push_back(std::move(s2));
	cout << endl << endl;
	
	cout << "vec.push_back(String(\"Yuan\")): ";
	vec.push_back(String("Yuan"));
	cout << endl << endl;

	// vec.push_back("Four");

}
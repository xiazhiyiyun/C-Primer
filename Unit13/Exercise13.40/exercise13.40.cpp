#include <string>
#include <iostream>
#include <memory>
#include "StrVec.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::allocator;
// using std::string;
// using std::string;

allocator<string> StrVec::alloc = allocator<string>();

int main(int argc, char const *argv[])
{
	StrVec svec;
	svec.push_back("Hello");

	cout << svec.size() << " "  << svec.capacity() << endl;

	for(auto begin = svec.begin(); begin != svec.end(); ++begin)
	{
		cout << *begin << " ";
	}
	cout << endl << endl;

	svec.push_back("World");
	cout << svec.size() << " "  << svec.capacity() << endl;

	for(auto begin = svec.begin(); begin != svec.end(); ++begin)
	{
		cout << *begin << " ";
	}
	cout << endl << endl;

	StrVec svec1{"initializer","list"};
	cout << svec1.size() << " "  << svec1.capacity() << endl;

	for(auto begin = svec1.begin(); begin != svec1.end(); ++begin)
	{
		cout << *begin << " ";
	}
	cout << endl;

	// for(const auto point:svec)
	// {
	// }
	// cout << endl;
	return 0;
}
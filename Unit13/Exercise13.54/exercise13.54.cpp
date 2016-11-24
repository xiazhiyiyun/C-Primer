#include <iostream>
#include <string>
#include "HasPtr.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;


int main(int argc, char const *argv[])
{
	HasPtr h1("Hello");
	HasPtr h2("World");
	HasPtr h3 = h1;
	cout << *h1 << endl;
	cout << *h2 << endl;
	cout << *h3 << endl;
	//exercise13.54.cpp:19:5: error: ambiguous overload for ‘operator=’ 
	//(operand types are ‘HasPtr’ and ‘std::remove_reference<HasPtr&>::type {aka HasPtr}’)h3 = std::move(h2);

	// h3 = std::move(h2);
	// cout << *h3 << endl;
	return 0;
}
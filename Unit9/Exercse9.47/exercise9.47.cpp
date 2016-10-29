#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char const *argv[])
{
	string str("ab2c3d7R4E6");
	string num("0123456789");
	string ablm("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string::size_type offset = 0;
	string::size_type i;
	while (( i = str.find_first_of(num,offset)) != string::npos)
	{
		cout << str[i] << " ";
		offset = i + 1;
	}

	cout << endl;

	offset = 0;
	while (( i = str.find_first_of(ablm,offset)) != string::npos)
	{
		cout << str[i] << " ";
		offset = i + 1;
	}

	cout << endl;

	offset = 0;
	while (( i = str.find_first_not_of(ablm,offset)) != string::npos)
	{
		cout << str[i] << " ";
		offset = i + 1;
	}

	cout << endl;

	offset = 0;
	while (( i = str.find_first_not_of(num,offset)) != string::npos)
	{
		cout << str[i] << " ";
		offset = i + 1;
	}

	cout << endl;

	// unsigned i          = -1;
	// long unsigned l     = -1;
	// string::size_type j = -1;
	// size_t k            = -1; 	

	// cout << "sizeof(unsigned): " << sizeof(unsigned) << endl;
	// cout << i << endl;
	// cout << "sizeof(long unsigned): " << sizeof(long unsigned) << endl;
	// cout << l << endl;
	// cout << "sizeof(string::size_type): " << sizeof(string::size_type) << endl;
	// cout << j << endl;
	// cout << "sizeof(size_t): " << sizeof(size_t) << endl;
	// cout << k << endl;

	return 0;
}
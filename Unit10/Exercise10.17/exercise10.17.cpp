#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <fstream>
#include "Sales_data.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;

bool compareIsbn(Sales_data s1,Sales_data s2);

int main(int argc, char const *argv[])
{
	ifstream in("Sales_data.txt");

	if(!in)
	{
		cout << "Error: cannot open file!" << endl;
		return -1;
	}

	Sales_data s1;
	vector<Sales_data> vec;
	while( read(in,s1) )
	{
		vec.push_back(s1);
	}

	for(const auto & val: vec)
	{
		print(cout,val);
		cout << endl;
	}
	cout << endl;
	sort(vec.begin(), vec.end(),[](const Sales_data &s1,const Sales_data & s2) {return s1.isbn() < s2.isbn();});

	for(const auto & val: vec)
	{
		print(cout,val);
		cout << endl;
	}

	return 0;
}

bool compareIsbn(Sales_data s1,Sales_data s2)
{
	return s1.isbn() < s2.isbn();
}
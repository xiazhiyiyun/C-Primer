#include <list>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iterator>
#include <fstream>
#include <functional>

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;

int main(int argc, char const *argv[])
{
	ifstream in("in.file");

	if(!in)
	{
		cout << "ERROR" << endl;
	}

	istream_iterator<int> is(in),eof;
	ostream_iterator<int> out(cout," ");

	list<int> vec(is,eof);
	auto iter = find(vec.crbegin(),vec.crend(),0);
	cout << *iter << endl;
	cout << endl;
	copy(vec.cbegin(),vec.cend(),out);
	cout << endl;
	copy(iter.base(),vec.cend(),out);
	cout << endl;
	// copy(vec.crbegin(),vec.crend(),out);
	return 0;
}
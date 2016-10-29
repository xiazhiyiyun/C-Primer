#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iterator>
#include <functional>

using std::vector;
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

	vector<int> vec(is,eof);

	copy(vec.cbegin(),vec.cend(),out);
	cout << endl;

	vector<int>::reverse_iterator re(vec.begin() + 2);
	vector<int>::reverse_iterator rb(vec.begin() + 7);
	copy(rb,re,out);
	cout << endl;

	copy(vec.rbegin()+3,vec.rbegin()+8,out);
	cout << endl;

	return 0;
}
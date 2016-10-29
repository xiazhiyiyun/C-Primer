#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <fstream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;

int main(int argc, char const *argv[])
{
	istream_iterator<string> is(cin),eof;
	ostream_iterator<string> os(cout, " ");

	vector<string> vec{is,eof};
	copy(vec.begin(),vec.end(),os);
	cout << endl;
	
	auto  it = partition(vec.begin(), vec.end(),[](string s) {return s.size() > 5;});
	copy(vec.begin(),it,os);
	cout << endl;

	return 0;
}
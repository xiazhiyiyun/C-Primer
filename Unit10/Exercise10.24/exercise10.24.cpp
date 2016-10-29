#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <fstream>
#include <functional>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using namespace std::placeholders;

bool bigger(int i, const  string &s);

int main(int argc, char const *argv[])
{
	istream_iterator<int> in(cin),eof;
	std::vector<int> vec(in,eof);

	string s("string");
	auto iter = find_if(vec.begin(),vec.end(),bind(bigger,_1,s));
	cout <<  *iter << endl;
	return 0;
}

bool bigger(int i, const  string &s)
{
	if(i > s.size())
	{
		return true;
	}
	return false;
}
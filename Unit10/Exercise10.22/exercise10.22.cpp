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

void elimDups(vector<string> &vec);
void biggies(vector<string> &vec,vector<string>::size_type sz);
bool smaller(const string &s,string::size_type sz);

int main(int argc, char const *argv[])
{
	istream_iterator<string> inIter(cin),eof;
	vector<string> vec(inIter,eof);
	biggies(vec,5);

	return 0;
}

void elimDups(vector<string> &vec)
{
	sort(vec.begin(), vec.end());
	auto it = unique(vec.begin(), vec.end());
	vec.erase(it,vec.end());
}

void biggies(vector<string> &vec,vector<string>::size_type sz)
{
	ostream_iterator<string> outIt(cout," ");
	elimDups(vec);
	copy(vec.begin(),vec.end(),outIt);
	cout << endl;

	auto iter = partition(vec.begin(),vec.end(),bind(smaller,_1,6));
	copy(vec.begin(),vec.end(),outIt);
	cout << endl;
	
	// auto iter = find_if(vec.begin(), vec.end(),[sz](const string &s) { return s.size() >= sz; });
	copy(vec.begin(),iter,outIt);
	cout << endl;
}

bool smaller(const string &s,string::size_type sz)
{
	if(s.size() <= sz)
	{
		return true;
	}
	return false;
}
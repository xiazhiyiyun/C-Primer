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

void elimDups(vector<string> &vec);
void biggies(vector<string> &vec,vector<string>::size_type sz);

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

	stable_sort(vec.begin(),vec.end(),[](const string &s1,const string & s2) { return s1.size() < s2.size(); });
	copy(vec.begin(),vec.end(),outIt);
	cout << endl;
	
	auto iter = find_if(vec.begin(), vec.end(),[sz](const string &s) { return s.size() >= sz; });
	copy(iter,vec.end(),outIt);
	cout << endl;
}
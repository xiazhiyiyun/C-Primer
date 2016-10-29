#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;

// using namespace std;

void elimDups(vector<string> &vec);
bool isShorter(string s1,string s2);

int main(int argc, char const *argv[])
{
	istream_iterator<string> is(cin),eof;
	ostream_iterator<string> os(cout, " ");

	vector<string> vec{is,eof};
	copy(vec.begin(),vec.end(),os);
	cout << endl;
	
	elimDups(vec);
	copy(vec.begin(),vec.end(),os);
	cout << endl;

	
	// stable_sort(vec.begin(),vec.end(),[](string s1,string s2) { return s1.size() < s2.size(); });
	stable_sort(vec.begin(),vec.end(),isShorter);
	copy(vec.begin(),vec.end(),os);
	cout << endl;

	return 0;
}

void elimDups(vector<string> &vec)
{
	sort(vec.begin(), vec.end());
	auto it = unique(vec.begin(), vec.end());
	vec.erase(it,vec.end());
}

bool isShorter(string s1,string s2)
{
	return s1.size() < s2.size();
}
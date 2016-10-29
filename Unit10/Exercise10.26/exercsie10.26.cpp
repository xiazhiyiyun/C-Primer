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
using std::back_inserter;

int main(int argc, char const *argv[])
{
	istream_iterator<int> is(cin),eof;
	vector<int> vec(is,eof);
	sort(vec.begin(),vec.end());

	vector<int> vec1;
	unique_copy(vec.begin(),vec.end(),back_inserter(vec1));

	ostream_iterator<int> out(cout," ");
	copy(vec.begin(),vec.end(),out);
	cout << endl;
	copy(vec1.begin(),vec1.end(),out);

	return 0;
}
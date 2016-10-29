#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <fstream>
#include <functional>

using std::vector;
using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::front_inserter;
using std::back_inserter;
using std::inserter;

int main(int argc, char const *argv[])
{
	std::vector<int> vec{1,2,3,4,5,6,7,8,9};
	deque<int> vec1;
	deque<int> vec2;
	deque<int> vec3;

	copy(vec.begin(),vec.end(),front_inserter(vec1));
	copy(vec.begin(),vec.end(),back_inserter(vec2));
	copy(vec.begin(),vec.end(),inserter(vec3,vec3.begin()));

	ostream_iterator<int> out(cout," ");
	copy(vec1.begin(),vec1.end(),out);
	cout << endl;

	copy(vec2.begin(),vec2.end(),out);
	cout << endl;
	
	copy(vec3.begin(),vec3.end(),out);
	cout << endl;
	return 0;
}
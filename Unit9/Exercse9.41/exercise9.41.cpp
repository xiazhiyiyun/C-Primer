#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	vector<char> vec_char{'h','e','l','l','o'};
	string str(vec_char.begin(), vec_char.end());
	cout << str << endl;

	string str1(vec_char.data(),vec_char.size());
	cout << str1 << endl;

	return 0;
}
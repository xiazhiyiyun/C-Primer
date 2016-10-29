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
	int i = 10;
	auto call = [i](int j) {return i+j;};
	cout << call(3) << endl;
	return 0;
}
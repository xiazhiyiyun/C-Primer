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
	int i = 5;
	auto f = [i]() mutable ->bool { if(i > 0) {--i;} return i; };

	while(f())
	{
		cout << "TRUE" << endl;
	}
	cout << "False" << endl;
	return 0;
}
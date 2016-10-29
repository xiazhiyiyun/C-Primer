#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char const *argv[])
{
	string name("r2d2");
	string numbers("0123456789");

	auto pos = name.find(numbers);
	cout << pos << endl;
	return 0;
}

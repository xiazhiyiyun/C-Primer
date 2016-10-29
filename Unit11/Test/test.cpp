#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>
#include <vector>
#include <utility>

using std::ifstream;
using std::string;
using std::back_inserter;
using std::map;
using std::set;
using std::vector;
using std::pair;
using std::make_pair;
using std::cin;
using std::endl;
using std::cout;

int main(int argc, char const *argv[])
{
	set<string> str{"Cell","Hi","World"};

	str.insert(str.find("Hi"),"Ami");
	str.insert(str.begin(),"Bmi");

	for(const auto & val:str)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

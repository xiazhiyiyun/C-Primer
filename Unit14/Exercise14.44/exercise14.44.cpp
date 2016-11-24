#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::modulus;
using std::function;
using std::map;
using std::pair;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
	typedef function<int(int,int)> Fun;
	map<string,Fun> fun_map{
		{"+",std::plus<int>()},
		{"-",std::minus<int>()},
		{"*",std::modulus<int>()},
		{"/",std::modulus<int>()}
	};

	int left,right;
	string op;
	cin >> left >> op >> right;
	cout << endl;
	cout << fun_map[op](left,right) << endl;
	return 0;
}
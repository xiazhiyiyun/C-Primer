#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::modulus;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
	vector<int>	 vec{1,2,3,45,6};
	auto num = count_if(vec.begin(),vec.end(),bind(modulus<int>(),_1,1));
	cout << num << endl;
	return 0;
}
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <list>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(int argc, char const *argv[])
{
	std::vector<int> vec_int{0,1,2,3,4,5,6,7,8,9};
	for(auto val:vec_int)
	{
		cout << val << " ";
	}
	cout << endl;

	fill_n(vec_int.begin(),vec_int.size(),0);

	for(auto val:vec_int)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
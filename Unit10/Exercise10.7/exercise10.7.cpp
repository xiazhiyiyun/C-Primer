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
using std::list;

int main(int argc, char const *argv[])
{
	std::vector<int> vec_int{0,1,2,3,4,5,6,7,8,9};	
	std::list<int> lis_int;

	for(auto val:vec_int)
	{
		cout << val << " ";
	}
	cout << endl;

	for(auto val:lis_int)
	{
		cout << val << " ";
	}
	cout << endl;

	copy(vec_int.cbegin(),vec_int.cend(),lis_int.begin());
	copy(vec_int.cbegin(),vec_int.cend(),back_inserter(lis_int));

	for(auto val:vec_int)
	{
		cout << val << " ";
	}
	cout << endl;

	for(auto val:lis_int)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
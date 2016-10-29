#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::vector;

void elimDups(std::list<int> &lis_int);

int main(int argc, char const *argv[])
{
	std::list<int> lis_int{4,12,4,5,7,6,7,8,7,5,34,2,2,0,4};
	
	for(auto val:lis_int)
	{
		cout << val << " ";
	}
	cout << endl;

	elimDups(lis_int);

	for(auto val:lis_int)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

void elimDups(std::list<int> &lis_int)
{	
	lis_int.sort();

	for(auto val:lis_int)
	{
		cout << val << " ";
	}
	cout << endl;

	lis_int.unique();
	for(auto val:lis_int)
	{
		cout << val << " ";
	}
	cout << endl;
}	
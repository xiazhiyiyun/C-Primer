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

void elimDups(std::vector<int> &vec_int);

int main(int argc, char const *argv[])
{
	std::vector<int> vec_int{4,12,4,5,7,6,7,8,7,5,34,2,2,0,4};
	
	for(auto val:vec_int)
	{
		cout << val << " ";
	}
	cout << endl;

	elimDups(vec_int);

	for(auto val:vec_int)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

void elimDups(std::vector<int> &vec_int)
{
	sort(vec_int.begin(), vec_int.end());

	for(auto val:vec_int)
	{
		cout << val << " ";
	}
	cout << endl;

	auto iter = unique(vec_int.begin(), vec_int.end());
	for(auto val:vec_int)
	{
		cout << val << " ";
	}
	cout << endl;

	vec_int.erase(iter,vec_int.end());
	for(auto val:vec_int)
	{
		cout << val << " ";
	}
	cout << endl;
	
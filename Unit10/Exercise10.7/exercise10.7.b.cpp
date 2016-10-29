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
	std::vector<int> vec_int;
	cout << "vec_int.size(): " << vec_int.size() << endl;
	cout << "vec_int.capacity(): " << vec_int.capacity() << endl;

	vec_int.resize(10);
	cout << "vec_int.size(): " << vec_int.size() << endl;
	cout << "vec_int.capacity(): " << vec_int.capacity() << endl;

	for(auto val:vec_int)
	{
		cout << val << " ";
	}
	cout << endl;


	// fill_n(back_inserter(vec_int),10,0);
	fill_n(vec_int.begin(),10,10);

	for(auto val:vec_int)
	{
		cout << val << " ";
	}
	cout << endl;

	cout << "vec_int.size(): " << vec_int.size() << endl;
	cout << "vec_int.capacity(): " << vec_int.capacity() << endl;
	return 0;
}
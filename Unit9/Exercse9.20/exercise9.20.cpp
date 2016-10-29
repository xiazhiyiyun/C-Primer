#include <deque>
#include <iostream>
#include <iterator>
#include <string>
#include <list>

using std::string;
using std::deque;
using std::list;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	list<int> lis_int{1,2,3,4,5,6,7,8,9,0};
	deque<int> deq_int1;
	deque<int> deq_int2;

	// split(lis_int,deq_int1,deq_int2);

	for(const auto &val:lis_int )
	{
		if( val%2 == 0 )
		{
			deq_int1.push_back(val);
		}
		else
		{
			deq_int2.push_back(val);
		}
	}

	cout << "lis_int: ";
	for(const auto &val:lis_int )
	{
		cout << val << " ";
	}
	cout << endl;

	cout << "deq_int1: ";
	for(const auto &val:deq_int1 )
	{
		cout << val << " ";
	}
	cout << endl;

	cout << "deq_int2: ";
	for(const auto &val:deq_int2 )
	{
		cout << val << " ";
	}
	cout << endl;

	return 0;
}
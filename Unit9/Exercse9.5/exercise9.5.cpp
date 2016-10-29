#include <vector>
#include <iostream>
#include <iterator>

using std::vector;
using std::cout;
using std::endl;

std::vector<int>::iterator findIter(std::vector<int>::iterator begin,std::vector<int>::iterator end,int val);


int main()
{
	std::vector<int> vec_int{1,2,3,4,5,6,6,7,9,0};

	auto it = findIter(vec_int.begin(),vec_int.end(),6);
	cout << (it != vec_int.end() ? "FIND" : "NOT FIND") << endl;
	it = findIter(vec_int.begin(),vec_int.end(),8);
	cout << (it != vec_int.end() ? "FIND" : "NOT FIND") << endl;
}

std::vector<int>::iterator findIter(std::vector<int>::iterator begin,std::vector<int>::iterator end,int val)
{
	for(;begin != end;++begin)
	{
		if(*begin == val)
		{
			return begin;
		}
	}

	return end;
}
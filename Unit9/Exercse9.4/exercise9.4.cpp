#include <vector>
#include <iostream>
#include <iterator>

using std::vector;
using std::cout;
using std::endl;

bool findInt(std::vector<int>::iterator begin,std::vector<int>::iterator end,int val);


int main()
{
	std::vector<int> vec_int{1,2,3,4,5,6,6,7,9,0};

	const bool flag = true;
	bool res = findInt(vec_int.begin(),vec_int.end(),6);
	cout << (res == true ? "true" : "false") << endl;
	res = findInt(vec_int.begin(),vec_int.end(),8);
	cout << (res == true ? "true" : "false") << endl ;
}

bool findInt(std::vector<int>::iterator begin,std::vector<int>::iterator end,int val)
{
	for(;begin != end;++begin)
	{
		if(*begin == val)
		{
			return true;
		}
	}

	return false;
}
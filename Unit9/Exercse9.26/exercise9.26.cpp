#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <array>

int main(int argc, char const *argv[])
{

	std::array<int,11> arr_int = {0,1,1,2,3,5,8,13,21,55,89};
	std::vector<int> vec_int(arr_int.begin(), arr_int.end());

	std::list<int> lis_int(arr_int.begin(),arr_int.end());

	for (std::vector<int>::iterator i = vec_int.begin(); i != vec_int.end(); ++i)
	{
		if(*i % 2 == 0)
		{
			i = vec_int.erase(i);
			--i;

		}
	}

	for (std::list<int>::iterator i = lis_int.begin(); i != lis_int.end(); ++i)
	{
		if(*i % 2 == 1)
		{
			i = lis_int.erase(i);
			--i;
		}
	}

	for (std::vector<int>::iterator i = vec_int.begin(); i != vec_int.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	for (std::list<int>::iterator i = lis_int.begin(); i != lis_int.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	return 0;
}
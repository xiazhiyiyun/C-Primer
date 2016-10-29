#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	std::vector<int> vec_int{1,2,3,4,5,6,7,8,9,0};

	auto begin = vec_int.begin();

	while(begin != vec_int.end())
	{
		++begin;
		begin = vec_int.insert(begin,42);
		// vec_int.insert(begin,42);
		++begin;
	}

	for(const auto &val : vec_int)
	{
		std::cout << val << " " ;
	}
	std::cout << std::endl;

	
	return 0;
}
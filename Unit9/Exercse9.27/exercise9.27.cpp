#include <forward_list>
#include <string>
#include <iostream>
#include <iterator>

int main(int argc, char const *argv[])
{
	std::forward_list<int> flis_int{1,2,3,4,5,6,7,8,9,0};

	for(const auto &val : flis_int)
	{
		std::cout << val << " " ;
	}
	std::cout << std::endl;

	auto prev = flis_int.before_begin();
	auto curr = flis_int.begin();
	while(curr != flis_int.end())
	{
		if( *curr%2 != 0)
		{
			curr = flis_int.erase_after(prev);
		}else
		{
			prev = curr++;
		}
	}

	for(const auto &val : flis_int)
	{
		std::cout << val << " " ;
	}
	std::cout << std::endl;

	return 0;
}
#include <algorithm>
#include <list>
#include <iostream>


int main()
{
	std::list<int> lis_int{0,1,2,3,4,4,5,5,6,5,7};
	for(int i = 0; i < 10; ++i)
	{
		auto res = count(lis_int.begin(),lis_int.end(),i);
		std::cout << "find " << i << " " << res << " times" << std::endl;
	}
	return 0;
}
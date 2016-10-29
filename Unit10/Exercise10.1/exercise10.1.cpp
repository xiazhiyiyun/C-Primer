#include <algorithm>
#include <vector>
#include <iostream>


int main()
{
	std::vector<int> vec_int{0,1,2,3,4,4,5,5,6,5,7};
	for(int i = 0; i < 10; ++i)
	{
		auto res = count(vec_int.begin(),vec_int.end(),i);
		std::cout << "find " << i << " " << res << " times" << std::endl;
	}
	return 0;
}
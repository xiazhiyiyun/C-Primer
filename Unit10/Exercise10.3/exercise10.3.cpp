#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
	std::vector<int> vec_int{0,1,2,3,4,4,5,5,6,5,7};
	auto res = accumulate(vec_int.begin(), vec_int.end(),0)	;
	std::cout << "accumulate: cd " << res << std::endl;
	return 0;
}
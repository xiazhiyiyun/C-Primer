#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
	std::vector<double> vec_int{0,1.2,2.4,3.9,4.5,4,5,5,6,5,7};
	auto res = accumulate(vec_int.begin(), vec_int.end(),0)	;
	std::cout << "accumulate: " << res << std::endl;

	
	double i = 2.3;
	double j = 2.4;
	int k   = i + j;
	std::cout << "double i = " << i << std::endl;
	std::cout << "double j = " << j << std::endl;
	std::cout << "i + j    = " << k << std::endl;

	return 0;
}
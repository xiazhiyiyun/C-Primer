#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
	std::vector<int> vec_int{1};

	if(!vec_int.empty())
	{
		auto val = *vec_int.begin(),val2 = vec_int.front();
		auto last = vec_int.end();
		auto val3 = *(--last);
		auto val4 = vec_int.back();

		std::cout << "val = *vec_int.begin() " << val << std::endl;
		std::cout << "val2 = vec_int.front() " << val2 << std::endl;
		std::cout << "val3 = *(--last) " << val3 << std::endl;
		std::cout << "val4 = vec_int.back() " << val4 << std::endl;

		val2 = 2;
		std::cout << "val2 = " << val2 << std::endl;
		std::cout << "vec_int.front() " << vec_int.front() << std::endl;
		val4 = 3;
		std::cout << "val4 =  " << val4 << std::endl;
		std::cout << "vec_int.back() " << vec_int.back() << std::endl;

	}


	return 0;
}
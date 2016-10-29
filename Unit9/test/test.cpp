#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

int main(int argc, char const *argv[])
{
	// std::vector<int> vec_int{1,2,3,4,5,6,8,9};
	// vec_int.reserve(10);

	// if(vec_int.capacity()  > vec_int.size())
	// {
	// 	auto item = find(vec_int.begin(),vec_int.end(),8);
	// 	std::cout << "*item = " << *item << std::endl;
	// 	auto item1 = vec_int.insert(item,7);
	// 	std::cout << "*item = " << *item-- << std::endl;
	// 	std::cout << "*item = " << *item-- << std::endl;
	// 	std::cout << "*item = " << *item-- << std::endl;
	// 	std::cout << "*item = " << *item-- << std::endl;
	// 	// std::cout << "*item = " << *item++ << std::endl;

	// 	std::cout << "*item1 = " << *item1 << std::endl;

	// }

	std::vector<int> vec_int;
	for(int i = 0 ; i < 24 ; ++i)
	{
		vec_int.push_back(i);
		std::cout << "vec_int.size() " << vec_int.size() << " ";
		std::cout << "vec_int.capacity() " << vec_int.capacity() << std::endl;
	}
	// for(auto val:vec_int)
	// {
	// 	std::cout << "val = " << val << std::endl;
	// }
	return 0;
}
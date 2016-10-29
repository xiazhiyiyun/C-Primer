#include <vector>
#include <iterator>
#include <iostream>

bool isEqual(std::vector<int> vec_int1,std::vector<int> vec_int2);

int main(int argc, char const *argv[])
{
	std::vector<int> vec_int1{1,2,3,4,5};
	std::vector<int> vec_int2{1,2,3,4,5};
	std::vector<int> vec_int3{1,1,2,3,4,5};

	std::cout << ( isEqual(vec_int1,vec_int2) ? "true" : "false" ) << std::endl;
	std::cout << ( isEqual(vec_int1,vec_int3) ? "true" : "false" ) << std::endl;

	return 0;
}

bool isEqual(std::vector<int> vec_int1,std::vector<int> vec_int2)
{
	auto iter1 = vec_int1.begin(),iter2 = vec_int2.begin();
	for(;iter1 != vec_int1.end() && iter2 != vec_int2.end();++iter1,++iter2)
	{
		if(*iter1 != *iter2)
			return false;	
	}

	if(iter1 == vec_int1.end() && iter2 == vec_int2.end())
	{
		return true;
	}

	return false;
}
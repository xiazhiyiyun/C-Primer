#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <list>

int main(int argc, char const *argv[])
{
	const char* s = "name";
	const char* s1 = "name";
	std::string str = "name" ;

	if(s == s1)
	{
		std::cout << "s == s1" << std::endl;
	}
	if(s == str)
	{
		std::cout << "s == str" << std::endl;
	}
	
	printf("const char *s1: %p\n", s);
	printf("const char *s1: %p\n", s1);
	printf("const char *str.c_str(): %p\n", str.c_str());


	std::vector<const char *> vec_char{"hello","world"};
	std::list<const char *> lis_char{"hello","world"};
	auto it = vec_char.begin();
	auto iter = lis_char.begin();
	for(;it != vec_char.end() && iter != lis_char.end();++it,++iter)
	{
		printf("vec_char[]: %p\n", *it);
		printf("lis_char[]: %p\n", *iter);
	}

	auto res = equal(vec_char.begin(), vec_char.end(),lis_char.begin());
	std::cout << (res ? "TRUE" : "FALSE") << std::endl;
	return 0;
}
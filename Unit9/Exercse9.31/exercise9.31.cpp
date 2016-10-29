#include <forward_list>
#include <string>
#include <iostream>
#include <iterator>

using std::forward_list;
using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	forward_list<int> flis_int{1,2,3,4,5,6,7,8,9,0};

	auto prev = flis_int.before_begin();
	auto curr = flis_int.begin();
	while(curr != flis_int.end())
	{
		if(*curr & 1)
		{
			curr = flis_int.insert_after(curr,*curr);
			prev = curr;
			++curr;
		}else
		{
			curr = flis_int.erase_after(prev);
		}
	}

	for(const auto &val : flis_int)
	{
		std::cout << val << " " ;
	}
	std::cout << std::endl;

	return 0;
}
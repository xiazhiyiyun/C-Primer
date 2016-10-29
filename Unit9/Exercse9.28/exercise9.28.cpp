#include <forward_list>
#include <string>
#include <iostream>
#include <iterator>

using std::forward_list;
using std::string;
using std::cout;
using std::endl;

forward_list<string>::iterator insert_string(forward_list<string> & flis_str,string s1,string s2);

int main(int argc, char const *argv[])
{
	forward_list<string> flis_str{"hello","world"};
	auto it = insert_string(flis_str,string("hello"),string("hi"));
	
	std::cout << *it << std::endl;

	for(const auto &val : flis_str)
	{
		std::cout << val << " " ;
	}
	std::cout << std::endl;

	it = insert_string(flis_str,string("hllo"),string("hi"));

	std::cout << *it << std::endl;
	
	for(const auto &val : flis_str)
	{
		std::cout << val << " " ;
	}
	std::cout << std::endl;

	return 0;
}

forward_list<string>::iterator insert_string(forward_list<string> & flis_str,string s1,string s2)
{
	auto prev = flis_str.before_begin();
	auto curr = flis_str.begin();
	while(curr != flis_str.end())
	{
		if( *curr == s1	)
		{
			return flis_str.insert_after(curr,s2);
		}else
		{
			++curr;
		}
		++prev;
	}
	return flis_str.insert_after(prev,s2);

}
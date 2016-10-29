#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <string>

using std::vector;
using std::list;
using std::string;
using std::cout;
using std::endl;

int main() 
{
	list<char *> lis_pch{(char *)"hello",(char *)("world")};
	char * s = (char *)"hello";
	
	vector<string> vec_str;

	vec_str.assign(lis_pch.begin(), lis_pch.end());

	for(auto it:vec_str)
	{
		cout << it << " ";
	}
	cout << endl;
}
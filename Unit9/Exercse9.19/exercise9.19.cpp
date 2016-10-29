#include <deque>
#include <iostream>
#include <iterator>
#include <string>
#include <list>

using std::string;
using std::deque;
using std::list;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	string word;
	list<string> lis_str;
	
	while(cin>>word)
	{
		lis_str.push_back(word);
	}	

	for(auto it = lis_str.begin();it != lis_str.end(); ++it)
	{
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}
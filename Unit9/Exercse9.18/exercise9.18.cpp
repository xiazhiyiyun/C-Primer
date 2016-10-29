#include <deque>
#include <iostream>
#include <iterator>
#include <string>

using std::string;
using std::deque;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	string word;
	deque<string> deq_str;
	
	while(cin>>word)
	{
		deq_str.push_back(word);
	}	

	for(auto it = deq_str.begin();it != deq_str.end(); ++it)
	{
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}
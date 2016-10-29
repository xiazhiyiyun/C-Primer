#include <vector>
#include <iostream>
#include <iterator>
#include <string>
#include <list>

using std::string;
using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	string word;
	std::vector<string> vec_str;

	auto iter = vec_str.begin();

	while(cin >> word)
	{
		iter = vec_str.insert(iter,word);
	}

	cout << "vec_str: ";
	for(const auto &val:	vec_str)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
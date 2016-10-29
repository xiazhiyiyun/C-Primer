#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	// char s[200];
	// char c;
	// int i = 0;
	// while(cin>>c)
	// {
	// 	s[i++] = c;
	// }
	// s[i] = '\0';

	// string str(s);

	string str;
	str.reserve(100);
	char c;
	while(cin >> c)
	{
		str.push_back(c);
	}
	cout << str << endl;
}
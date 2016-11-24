#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
	const char *s1 = "Hello";
	const char *s2 = "World";

	char *s = new char[20];
	strcpy(s,s1);
	strcat(s,s2);
	cout << s << " " << strlen(s) << endl;

	string str1 = "Hello ";
	string str2 = "World!";
	string str3 = str1 + str2;
	strcpy(s,str3.c_str());
	cout << s << " " << strlen(s) << endl;

	delete []s;
	return 0;
}
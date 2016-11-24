#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	char *r = new char[21];

	char c;
	int l = 0;

	while(cin.get(c))
	{
		if(isspace(c))
			break;
		r[l++] = c;
		if(l == 20)
		{
			cout << "Full!" << endl;
			break;
		}
	}

	r[l] = '\0';
	cout << r << " " << strlen(r) << endl;
	// cout << "sizeof(r) " << sizeof(r) << endl;
	delete [] r;
	return 0;
}
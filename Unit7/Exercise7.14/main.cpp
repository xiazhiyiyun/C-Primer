#include "person.h"
#include <string>
#include <fstream>
#include <iostream>

using std::istream;
using std::ostream;
using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	ifstream in("person.txt");

	if(!in)
	{
		cout << "Cannot open file \"person.txt\"!" << endl;
		return -1;
	}

	person item;
	
	while(read(in,item))
	{
		print(cout,item);
	}

	return 0;
}
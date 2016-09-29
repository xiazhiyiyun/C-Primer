#include <string>
#include <iostream>
#include <fstream>
#include "Sales_data.h"

using std::cout;
using std::cin;
using std::endl;
// using std::istream;
// using std::ostream;
using std::ifstream;

int main(int argc,char **argv)
{
	ifstream in("Sales_data.txt");
	if( !in )
	{
		cout << "Cannot open file \"Sales_data.txt\"" << endl;
		return -1;
	}

	Sales_data total;

	if( read(in,total) )
	{
		
		Sales_data item;

		while( read(in,item) )
		{
			if(total.isbn() == item.isbn())
			{
				total.combine(item);
			}
			else
			{
				print(cout,total);
				cout << endl;
				total = item;
			}
		}
		print(cout,total);
		cout << endl;
	}else
	{
		cout << "No data? End!" << endl;
	}

	in.close();

	return 0;
}
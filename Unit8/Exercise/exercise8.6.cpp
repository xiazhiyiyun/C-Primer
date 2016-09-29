#include <sting>
#include <iostream>
#include <fstream>
#include "Sale_data.h"

using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;

int main(int argc,char ** argv)
{
	if(argc != 2)
	{
		cerr << "Input the file to read" << endl;
	}

	ifstream in(argv[1]);
	
	if(!in)
	{
		cerr << "Input file is wrong!" << endl;
	}

	Sale_date total;

	if( read(in,total) )
	{
		Sale_date item;
		while( read(in,item) )
		{
			if( total.isbn == item.isbn )
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
		cerr << "No data?" << endl;
	}
}
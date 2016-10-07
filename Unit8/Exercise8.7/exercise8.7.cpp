#include <string>
#include <iostream>
#include <fstream>
#include "Sales_data.h"

using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;

int main(int argc,char ** argv)
{
	if(argc != 3)
	{
		cerr << "Input the file-name to read and the file-name to save the result." << endl;
		return -1;
	}

	ifstream in(argv[1]);
	ofstream out(argv[2],ofstream::app);

	if(!in)
	{
		cerr << "Input file is wrong!" << endl;
	}

	Sales_data total;

	if( read(in,total) )
	{
		Sales_data item;
		while( read(in,item) )
		{
			if( total.isbn() == item.isbn() )
			{
				total.combine(item);
			}
			else 
			{
				print(out,total);
				out << endl;
				total = item;
			}
		}
		print(out,total);
		out << endl;
	}else
	{
		cerr << "No data?" << endl;
	}
}

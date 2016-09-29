#include <string>
#include <iostream>
#include <fstream>
#include "Sales_data.h"

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::ifstream;

int main(int argc,char **argv)
{
	Sales_data data1;
	Sales_data data2("11111") ;
	Sales_data data3("22222",2,40) ;

	ifstream in("Sales_data.txt");
	if( !in )
	{
		cout << "Cannot open file \"Sales_data.txt\"" << endl;
		return -1;
	}

	Sales_data data4(in) ;
	in.close();

	print(cout,data1);
	cout << endl;
	print(cout,data2);
	cout << endl;
	print(cout,data3);
	cout << endl;
	print(cout,data4);
	cout << endl;
}
#include <iostream>
#include <fstream>
#include <string>
#include "person.h"

using std::istream;
using std::ostream;
using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

	std::ostream & print(std::ostream &out,const person &item);
	std::istream & read(std::istream &in,person &item);

ostream & print(ostream &out,const person & item)
{
	out << item.name << " " << item.address;
	return out;
}

istream & read(istream &in,person &item)
{
	in >> item.name >> item.address;
	return in;
}
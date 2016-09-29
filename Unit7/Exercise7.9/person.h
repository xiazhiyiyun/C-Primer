#include <string>
#include <iostream>

class person
{
public:
	person() {}
	~person() {}


	std::string getName() const		{ return name; }
	std::string getAddress() const	{ return address; }
	
public:	
	std::string name;
	std::string address;
};

std::ostream & print(std::ostream &out,const person &item);
std::istream & read(std::istream &in,person &item);

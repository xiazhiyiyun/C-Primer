#include <string>

class person
{
public:
	person()
	~person()
	std::string getName() const		{ return name; }
	std::string getAddress() const	{ return address; }
	
private:	
	std::string name;
	std::string address;
};
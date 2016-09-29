#include <iostream>
#include <string>

class Sales_data
{
public:
	Sales_data()	{}
	~Sales_data() 	{}
public:
	std::string isbn() const 		{ return bookNo; }
	double avg_price() const;	
	Sales_data & combine(const Sales_data &item);

public:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

Sales_data add( const Sales_data & item1,const Sales_data & item2);
std::istream & read(std::istream & in,Sales_data &item);
std::ostream & print(std::ostream & out,const Sales_data &item);
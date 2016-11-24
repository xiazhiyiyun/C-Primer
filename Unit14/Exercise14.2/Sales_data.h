#include <iostream>
#include <string>

class Sales_data;

Sales_data add( const Sales_data & item1,const Sales_data & item2);
std::istream & read(std::istream & in,Sales_data &item);
std::ostream & print(std::ostream & out,const Sales_data &item);

Sales_data operator+( const Sales_data & item1,const Sales_data & item2);
std::istream & operator>>(std::istream & in,Sales_data &item);
std::ostream & operator<<(std::ostream & out,const Sales_data &item);

class Sales_data
{
public:
	Sales_data() = default;
	Sales_data(std::string _bookNo):bookNo(_bookNo),units_sold(0),revenue(0.0) {}
	Sales_data(std::string _bookNo,unsigned u,double price):bookNo(_bookNo),units_sold(u),revenue(u*price) {}
	Sales_data(std::istream &in)
	{
		read(in,*this);
	}

	~Sales_data() 	{}
public:
	std::string isbn() const 		{ return bookNo; }
	double avg_price() const;	

	Sales_data & combine(const Sales_data &item);

public:


public:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};
#include <string>

class Sales_data
{
public:
	Sales_data():units_sold(0),revenue(0) {}
public:
	void isbn() const 		{ return bookNo; }
	double avg_price();
	Sales_data &combine(const Sales_data &item);

public:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

Sales_data add( const Sales_data &item1,con);
istream &read(istream &in,Sales_data item);
ostream &print(ostream &out,Sales_data item);
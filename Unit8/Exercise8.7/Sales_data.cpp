#include "Sales_data.h"
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

double Sales_data::avg_price() const
{
	if( units_sold > 0 )
		return revenue / units_sold;
	else 
		return 0;
}


Sales_data &Sales_data::combine(const Sales_data &item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

Sales_data add( const Sales_data &item1,const Sales_data &item2)
{
		Sales_data sum = item1;
		sum.combine(item2);
		return sum;
}

istream & read(istream &in,Sales_data &item)
{
	double price = 0;
	in >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	// print(cout,item);
	// cout << endl;
	return in;
}

ostream & print(ostream &out,const Sales_data &item)
{
	out << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return out;
}
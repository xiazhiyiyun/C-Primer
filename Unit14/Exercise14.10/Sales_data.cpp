#include "Sales_data.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;


//The const member function must define the const attribute too.
double Sales_data::avg_price () const
{
	if( units_sold > 0 )
		return revenue / units_sold;
	else 
		return 0;
}

Sales_data & Sales_data::combine(const Sales_data &item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	// print(cout,*this);
	// cout << endl;

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
	if(in)
		item.revenue = price * item.units_sold;
	else 
		item = Sales_data();
	// print(cout,item);
	// cout << endl;
	return in;
}

ostream & print(ostream &out,const Sales_data &item)
{
	out << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return out;
}

Sales_data operator+( const Sales_data & item1,const Sales_data & item2)
{
	Sales_data sum = item1;
	sum.combine(item2);
	return sum;
}

std::istream & operator>>(std::istream & in,Sales_data &item)
{
	double price = 0;
	in >> item.bookNo >> item.units_sold >> price;
	if(in)
		item.revenue = price * item.units_sold;
	else 
		item = Sales_data();
	// print(cout,item);
	// cout << endl;
	return in;
}

std::ostream & operator<<(std::ostream & out,const Sales_data &item)
{
	out << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return out;
}

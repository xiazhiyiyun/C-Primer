#include "Sale_data.h"

double Sales_data::avg_price()
{
	if( unit_sold > 0 )
		return revenue / unit_sold;
	else 
		return 0;
}


Sales_data &Sale_data::combine(const Sales_date &item)
{
	unit_sold += item.unit_sold;
	revenue += item.revenue;
	return *this;
}

Sales_data add( const Sales_data &item)
{

}

istream &read(istream &in,Sales_data item)
{

}

ostream &print(ostream &out,Sales_data item)
{

}

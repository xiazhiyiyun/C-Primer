#ifndef _BULK_QUOTE
#define _BULK_QUOTE

#include <string>
#include <iostream>
#include "Disc_Quote.h"

class Bulk_quote:public Disc_Quote
{
public:
	Bulk_quote() {}
	
	Bulk_quote(const std::string & _isbn,double _price,std::size_t _qty,double _discount):
		Disc_Quote(_isbn,_price,_qty,_discount) {}

public:
	virtual double net_price(std::size_t n) const
	{
		if(n > min_qty)
		{
			return n * (1 - discount) *price;
		}else
		{
			return n * price;
		}
	}
	
};

#endif
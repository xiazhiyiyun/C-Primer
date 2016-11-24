#ifndef _BULK_QUOTE
#define _BULK_QUOTE

#include <string>
#include <iostream>
#include "Quote.h"

class Bulk_quote:public Quote
{
public:
	Bulk_quote():min_qty(0),discount(0.0) 
	{}
	
	Bulk_quote(const std::string & _isbn,double _price,std::size_t _qty,double _discount):
		Quote(_isbn,_price),min_qty(_qty),discount(_discount) {}

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
	
private:
	std::size_t min_qty;
	double discount;
};

#endif
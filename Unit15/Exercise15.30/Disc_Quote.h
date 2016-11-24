#ifndef _DISC_QUOTE
#define _DISC_QUOTE

#include <string>
#include <iostream>
#include "Quote.h"

class Disc_Quote:public Quote
{
public:
	Disc_Quote():min_qty(0),discount(0.0) 
	{}
	
	Disc_Quote(const std::string & _isbn,double _price,std::size_t _qty,double _discount):
		Quote(_isbn,_price),min_qty(_qty),discount(_discount) {}

public:

	virtual double net_price(std::size_t n) const = 0;
	
protected:
	std::size_t min_qty;
	double discount;
};

#endif
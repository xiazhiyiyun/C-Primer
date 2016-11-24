#ifndef _DIS_QUOTE
#define _DIS_QUOTE

#include <string>
#include <iostream>
#include "Disc_Quote.h"

class Dis_Quote:public Disc_Quote
{
public:
	Dis_Quote():min_qty(0),discount(0.0) 
	{}
	
	Dis_Quote(const std::string & _isbn,double _price,std::size_t _qty,double _discount):
		Disc_Quote(_isbn,_price,_qty,_discount) {}

public:
	virtual Dis_Quote * clone() const &
	{
		return new Dis_Quote(*this);
	}

	virtual Dis_Quote * clone() &&
	{
		return new Dis_Quote(std::move(*this));
	}

	virtual double net_price(std::size_t n) const
	{
		if(n < min_qty)
		{
			return n * (1 - discount) *price;
		}else
		{
			return ( min_qty * (1 - discount) * price ) + ((n - min_qty) * price);
		}
	}
	
private:
	std::size_t min_qty;
	double discount;
};

#endif
#ifndef _QUOTE
#define _QUOTE

#include <string>
#include <iostream>

class Quote
{
public:
	Quote():price(0.0) {}
	Quote(const std::string &book,double _price):isbn(book),price(_price) 
	{
		std::cout << "Quote(const std::string &book,double _price):" << std::endl;
	}
	virtual ~Quote() 
	{
		std::cout << "~Quote():" << std::endl;

	}

public:
	std::string ISBN() const { return isbn; }

	virtual double net_price(std::size_t n) const
	{
		return n*price;
	}

protected:
	double price;

private:
	std::string isbn;
};

#endif
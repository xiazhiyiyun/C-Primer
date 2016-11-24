#ifndef _QUOTE
#define _QUOTE

#include <string>
class Basket;

class Quote
{
	friend class Basket;
public:
	Quote():price(0.0) {}
	Quote(const std::string &book,double _price):isbn(book),price(_price) {}
	virtual ~Quote() {}

public:
	virtual Quote * clone() const &
	{
		return new Quote(*this);
	}

	virtual Quote * clone() &&
	{
		return new Quote(std::move(*this));
	}
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
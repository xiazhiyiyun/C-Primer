#ifndef _BASKET
#define _BASKET

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <memory>
#include <map>
#include <set>
#include "Bulk_quote.h"
#include "Quote.h"
#include "Disc_Quote.h"

using namespace std;

double print_total(std::ostream & os,const Quote & item,std::size_t n);

class Basket
{
public:
	Basket() {}
	~Basket() {}

public:
	void add_item(const Quote &sale)
	{
		items.insert(std::shared_ptr<Quote>(sale.clone()));
		// items.insert(sale);
	}

	void add_item(const Quote &&sale)
&	{
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
		// items.insert(sale);
	}

	double total_receipt(std::ostream &os) const
	{
		double sum = 0;
		for(auto iter = items.cbegin();iter != items.cend();iter = items.upper_bound(*iter))
		{
			sum = sum + print_total(os,**iter,items.count(*iter));
		}
		os << "Total Sale: " << sum << endl;
	}

private:	
	static bool compare(const std::shared_ptr<Quote> &lhs,const std::shared_ptr<Quote> &rhs)
	{
		return lhs->ISBN() < rhs->ISBN();
	}
private:	
	std::multiset<std::shared_ptr<Quote>,decltype(compare)*> items{compare};
};

#endif
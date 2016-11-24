#include <string>
#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Dis_Quote.h"

using namespace std;

double print_total(std::ostream & os,const Quote & item,std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.ISBN() << " #sold: " << n << " total due: " << ret << endl;
	return ret;
}

int main(int argc, char const *argv[])
{
	Bulk_quote b("001",10,5,0.2);
	Dis_Quote d("001",10,5,0.2);
	Quote q("002",10);
	print_total(cout,b,10);
	print_total(cout,q,10);
	print_total(cout,d,10);
	return 0;
}
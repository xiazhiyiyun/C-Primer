#include <string>
#include <iostream>
#include "Quote.h"

using namespace std;

double print_total(std::ostream & os,const Quote & item,std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.ISBN() << " #sold: " << n << " total due: " << ret << endl;
	return ret;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
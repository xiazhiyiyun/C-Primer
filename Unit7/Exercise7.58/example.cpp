#include <vector>
#include <iostream>


class Example
{
public:
	static double rate;
	static const int vecSize = 20;
	static std::vector<double> vec;	
};

//schould define in the global scope
double Example::rate = 10 ;
std::vector<double> Example::vec(10);

int main()
{


	std::cout << Example::rate << std::endl;

	for(int x = 0 ; x < Example::vec.size(); x++) 
	{
		std::cout << x << std::endl;
	}
}
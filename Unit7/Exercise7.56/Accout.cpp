#include <iostream>
#include <string>

class Accout
{

public:
	void calculate() { amount += amount * interestRate; }	
	static double rate() { return interestRate; }
	static void rate(double);

private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
};

void Accout::rate(double rate)
{
	interestRate = rate;
}

double Accout::initRate()
{
	return 2.3;
}

double Accout::interestRate = initRate();

int main() 
{
	std::cout << Accout::rate() << std::endl;
	Accout::rate(3.2);
	std::cout << Accout::rate() << std::endl;
}
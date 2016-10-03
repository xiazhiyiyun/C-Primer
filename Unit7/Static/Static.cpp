#include <iostream>

class Static
{
public:
	Static() {}
	~Static() {}

public:
	static void print() { std::cout << staticMem << std::endl; }
	static constexpr int staticMem = 10;
	static constexpr double staticMem1 = 10.2;
};
constexpr int Static::staticMem;
int main() 
{
	Static::print();
	std::cout << Static::staticMem << std::endl;
	std::cout << Static::staticMem1 << std::endl;

	const int & ref = Static::staticMem;
	std::cout << ref << std::endl;

}

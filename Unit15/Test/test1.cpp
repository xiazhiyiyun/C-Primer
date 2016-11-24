#include <iostream>

class Base
{
public:
	Base():base(10) {}
	~Base() {}
protected:
	int base;
};

class Dev:public Base
{
	friend void print(const Dev &);
public:
	Dev():Base(),dev(20) {}
	~Dev() {}
protected:
	int dev;
};

void print(const Dev &d)
{
	std::cout << d.base << std::endl;
	std::cout << d.dev << std::endl;
}

int main(int argc, char const *argv[])
{
	Dev d;
	print(d);
	return 0;
}
#include <iostream>

class Debug
{
public:
	constexpr Debug( bool b = true ): hw(b),io(b),other(b) {}
	constexpr Debug( bool h,bool i,bool o ):hw(h),io(i),other(o) {}

	constexpr bool any() { return hw||io||other; }

	void set_hw(bool b) { hw = b;}
	void set_io(bool b) { io = b;}
	void set_other(bool b) { other = b; }
private:
	bool hw;
	bool io;
	bool other;
};

int main() 
{
	constexpr Debug d(false);
	constexpr Debug d1;
	constexpr Debug d2(true,false,false);

	constexpr bool b = d.any();
	constexpr bool b1 = d1.any();
	constexpr bool b2 = d2.any();

	std::cout << b << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}
#include <iostream>
using namespace std;

struct Y;
struct X
{
	Y* str;
};

struct Y
{
	X* str;
};

int main()
{
	X x;
	Y y;
	cout << x.str << endl;
	cout << y.str << endl;
}

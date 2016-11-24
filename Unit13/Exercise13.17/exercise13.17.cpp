#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class numbered
{
	friend void fun(numbered a);
	friend void funref(numbered &a);
public:
	numbered():i(++max) {}
	numbered(const numbered &num):i(++max) {}
	numbered & operator=(const numbered &num) {i = ++max;	}
private:
	static int max;
	int i;
};


void fun(numbered a) {cout << a.i << endl;}
void funref(numbered &a) {cout << a.i << endl;}
int numbered::max =0;

int main(int argc, char const *argv[])
{
	numbered a, b = a, c = b;
	fun(a);
	fun(b);
	fun(c);
	funref(a);
	funref(b);
	funref(c);
	return 0;
}
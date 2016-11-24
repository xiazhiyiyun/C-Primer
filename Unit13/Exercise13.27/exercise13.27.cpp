#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class HasPtr
{
public:
	HasPtr(const string &s):ps(new string(s)),use(new int(0)) {++*use;}
	HasPtr(const HasPtr&rhs):ps(rhs.ps),use(rhs.use),i(rhs.i) {++*use;}
	HasPtr & operator=(const HasPtr &rhs)
	{
		++*rhs.use;
		if(--*rhs.use == 0)
		{
			delete rhs.ps;
			delete rhs.use;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		return *this;
	}

	string & operator*()
	{
		return *ps;
	}
	~HasPtr()
	{
		if(--use == 0)
		{
			delete ps;
			delete use;
		}
	}
private:
	string *ps;
	int *use;
	int i;
	
};
int main(int argc, char const *argv[])
{
	HasPtr h1("Hello");
	HasPtr h2 = h1;
	cout << *h1 << endl;
	cout << *h2 << endl;
	return 0;
}
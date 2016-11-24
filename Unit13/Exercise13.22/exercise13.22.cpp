#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class HasPtr
{
public:
	HasPtr(const string s = string()):s(new string(s)),i(0) {}
	HasPtr(const HasPtr &h):s(new string(*h.s)),i(h.i) {}
	~HasPtr() {delete s;}
	HasPtr & operator=(const HasPtr &rhs)
	{
		string *p = new string(*rhs.s);
		delete s;
		s = p;
		i = rhs.i;
	}
	string & operator*()
	{
		return *s;
	}
private:
	string *s;
	int i;
};

int main(int argc, char const *argv[])
{
	HasPtr h1("Hello");
	HasPtr h2("World");
	HasPtr h3 = h1;
	cout << *h1 << endl;
	cout << *h2 << endl;
	cout << *h3 << endl;
	return 0;
}
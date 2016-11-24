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
	HasPtr(const HasPtr &h):s(new string(*h.s)),i(h.i) 
	{
		cout << "----HasPtr(const HasPtr &h)----" << endl;
	}
	
	HasPtr(HasPtr &&h):s(h.s),i(h.i) 
	{

		cout << "----HasPtr(HasPtr &&h)----" << endl;
		h.s = nullptr;
		h.i = 0;
	}

	~HasPtr() {delete s;}

	// HasPtr & operator=(const HasPtr &rhs)
	// {
	// 	string *p = new string(*rhs.s);
	// 	delete s;
	// 	s = p;
	// 	i = rhs.i;
	// }
	HasPtr & operator=(HasPtr rhs)
	{
		cout << "----HasPtr & operator=(HasPtr rhs)----" << endl;
		swap(*this,rhs);
		return *this;
	}

	HasPtr & operator=(HasPtr &&rhs)
	{
		cout << "----HasPtr & operator=(HasPtr &&rhs)----" << endl;
		if(this != &rhs)
		{	
			delete s;
			s = rhs.s;
			i = rhs.i;
			rhs.s = nullptr;
			rhs.i = 0;
		}
		return *this;
	}

	void swap(HasPtr &lhs,HasPtr &rhs)
	{
		using std::swap;
		swap(lhs.s,rhs.s);
		swap(lhs.i,rhs.i);
	}

	string & operator*()
	{
		return *s;
	}

private:
	string *s;
	int i;
};

#include <iostream>
#include <string>
#include <new>

using std::string;
using std::cin;
using std::endl;
using std::cout;

class testCopyConstru
{
public:
	testCopyConstru(const string &s):p(new string(s)),num(1)
	{
		cout << "testCopyConstru()::this->*p = "<< *p << ",this->num = " << num <<endl;
	}

	testCopyConstru(const testCopyConstru &s):p(s.p),num(s.num+1) 
	{
		cout << "testCopyConstru(const testCopyConstru &)::this->*p = "<< *p << ",this->num = " << num <<endl;
	}
	~testCopyConstru() 
	{
		cout << "~testCopyConstru()::this->*p = "<< *p << ",this->num = " << num <<endl;
		if( num==1 )
		{
			if(p)
			{
				delete p;
				p = nullptr;
			}			
			--num;
		}else
		{
			--num;
		}
		// cout << "~testCopyConstru()::this->num = " << num <<endl;
	}

private:
	string *p;
	unsigned num;
	
};

int main(int argc, char const *argv[])
{
	testCopyConstru test1("testCopyConstru1");
	testCopyConstru test2 = string("testCopyConstru2");
	testCopyConstru test3 = test2;
	return 0;
}
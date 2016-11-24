#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void print(int val)
{
	printf("%d\n",val );
}

class Base
{
public:
	Base():val(10)
	{ 
		printf("Bade\n");
	}
	Base(int _val):val(_val)
	{ 
	}
	~Base() {}
	
public:
	int val;
};
class Dev:public Base
{
public:
	Dev():name("Dev") 
	{
		val = 11;
		printf("Dev\n");
	}
	Dev(string _name,int _val):Base(_val),name(_name)
	{

	}

	~Dev() {}
	Dev & operator=(const Dev &d)
	{
		name = d.name;
		val = d.val;
	}
public:
	string name;
	
};

int main(int argc, char const *argv[])
{
	//名字查找先于类型检查
	int print = 10;
	//通过作用域运算符可以调用被隐藏的名字
	::print(print);
	// print(10);

	Dev d1("Dev1",1);
	Dev d2("Dev2",2);
	cout << d1.name << " " << d1.val << endl;
	cout << d2.name << " " << d2.val << endl;
	d2 = d1;
	cout << d1.name << " " << d1.val << endl;
	cout << d2.name << " " << d2.val << endl;
	return 0;
}
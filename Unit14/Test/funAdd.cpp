#include <iostream>
#include <string>

using namespace std;

int f()
{
	cout << "f():"<< endl;
}

double g()
{
	cout << "g():"<< endl;
}



class Base 
{
public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
private:
	int i;
};

int main()
{
	Base b;
	cout << &b << endl;
	cout << "虚函数表地址：" << (int*)(&b) << endl;
    cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;
	// cout << (int *)&b << endl;
	cout << "sizeof(Base):" << sizeof(Base) << endl;

	typedef void(*Fun)(void);
	Fun pFun = 0;
	pFun = (Fun)*((int*)*(int*)(&b));
	pFun();
	pFun = (Fun)*(((int*)*(int*)(&b)) + 1);
	pFun();
	pFun = (Fun)*(((int*)*(int*)(&b)) + 2);
	pFun();
}
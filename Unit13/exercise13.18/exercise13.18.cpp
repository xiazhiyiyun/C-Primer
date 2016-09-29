#include <iostream>

using namespace std;

class Employee
{
public:
	Employee(){ ++index; }
	Employee(const string &_name):name(_name) { ++index; }
	//Employee(const Employee &Employ)

public:
	string name;
	static int index;
};

int Employee::index = 0;

int main()
{
	Employee A("A");
	cout << "A.name = " << A.name << " A.index = " << Employee::index << endl; 
	cout << "-------------------------------------" << endl;

	Employee B("B");
	cout << "B.name = " << B.name << " B.index = " << Employee::index << endl; 
	cout << "-------------------------------------" << endl;

	Employee C(A);
	cout << "C.name = " << C.name << " C.index = " << Employee::index << endl; 
	cout << "-------------------------------------" << endl;

	Employee D = B;
	cout << "D.name = " << D.name << " D.index = " << Employee::index << endl; 
	cout << "-------------------------------------" << endl;

	cout << "A.name = " << A.name << " A.index = " << Employee::index << endl; 
	cout << "B.name = " << B.name << " B.index = " << Employee::index << endl; 
	cout << "C.name = " << C.name << " C.index = " << Employee::index << endl; 
	cout << "D.name = " << D.name << " D.index = " << Employee::index << endl; 
}

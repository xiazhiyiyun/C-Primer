#include <iostream>

using namespace std;

class Employee
{
public:
	Employee(const string &_name = string()):name(_name),index(++currIndex) {}
	Employee(const Employee &em):name(em.name),index(++currIndex) {}
	Employee & operator=(const Employee &em)
	{
		name = em.name;
		index = ++currIndex;
	}

public:
	string name;
	int index;
	static int currIndex;
};

int Employee::currIndex = 0;

int main()
{
	Employee A("A");
	cout << "A.name = " << A.name << " A.index = " << A.index << endl; 
	cout << "-------------------------------------" << endl;

	Employee B("B");
	cout << "B.name = " << B.name << " B.index = " << B.index << endl; 
	cout << "-------------------------------------" << endl;

	Employee C(A);
	cout << "C.name = " << C.name << " C.index = " << C.index << endl; 
	cout << "-------------------------------------" << endl;

	Employee D = B;
	cout << "D.name = " << D.name << " D.index = " << D.index << endl; 
	cout << "-------------------------------------" << endl;
	D=B;
	cout << "A.name = " << A.name << " A.index = " << A.index << endl; 
	cout << "B.name = " << B.name << " B.index = " << B.index << endl; 
	cout << "C.name = " << C.name << " C.index = " << C.index << endl; 
	cout << "D.name = " << D.name << " D.index = " << D.index << endl; 
}

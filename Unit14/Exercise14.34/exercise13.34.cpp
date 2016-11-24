#include <iostream>
#include <string>

using namespace std;

class IfElseThen
{
public:
	int operator()(int i1,int i2,int i3)
	{
		return i1?i2:i3;
	}
		
};

int main(int argc, char const *argv[])
{
	IfElseThen IF;
	cout << IF(1,2,3) << endl;
	cout << IF(0,2,3) << endl;
	return 0;
}
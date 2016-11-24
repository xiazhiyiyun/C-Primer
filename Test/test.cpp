#include <string>
#include <iostream>
#include <new>

using namespace std;

class Test
{

public:
	Test():attr("nullStr") {}
	Test(string str):name(str),attr("nullStr") {}
	Test(string str1,string str2):name(str1),attr(str2) {}

	string get()
	{
		return name;
	}
	// ~Test()=delete;
private:
	string name;
	const string attr;
};

int main(int argc, char const *argv[])
{
	// Test test("Summer");
	// cout << test.get() << endl;
	Test *test1 = new Test("Summer");
	Test test2 = Test("Sunndy");
	Test test3 = test2;
	cout << test1->get() << endl;
	cout << test2.get() << endl;
	delete test1;
	return 0;
}


#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Foo
{
public:
	Foo() {}
	~Foo() {}

	Foo sorted() && 
	{
		cout << "Foo sorted() &&: " << endl;
		std::sort(data.begin(),data.end());
	}
	Foo sorted() const & 
	{
		cout << "Foo sorted() const &: " << endl;
		return Foo(*this).sorted();
	}
	// Foo sorted() const & 
	// {
	// 	cout << "Foo sorted() const &: " << endl;
	// 	Foo ret(*this);
	// 	return ret.sorted();
	// }
private:
	std::vector<int>	 data;
};
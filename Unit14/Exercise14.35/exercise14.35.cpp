#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PrintString
{
public:
	// PrintString(istream &_is = cin): is(_is) {}
	// PrintString(const PrintString &p) = delete;

	string operator()(istream &_in)
	{
		string word;
		if( getline(_in,word) )
			return word;
		return string();
	}
private:
	// istream & is;
	// char sep;
};

int main(int argc, char const *argv[])
{
	PrintString p;
	auto word = p(cin);
	cout << word << endl;
	return 0;
}
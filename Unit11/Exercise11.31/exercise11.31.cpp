#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <vector>
#include <utility>

using std::ifstream;
using std::string;
using std::pair;
using std::multimap;
using std::vector;
using std::cin;
using std::endl;
using std::cout;

void eraseBook(multimap<string,string> &book,const string & name);
void printBook(const multimap<string,string> &book);

int main(int argc, char const *argv[])
{
	multimap<string,string> book;
	book.insert({"zhang","C-Primer"});
	book.insert({"zhang","Effective"});
	book.insert({"li","stl"});
	book.insert({"li","program"});
	printBook(book);
	cout << endl;

	eraseBook(book,"li");
	printBook(book);
	cout << endl;
	
	eraseBook(book,"su");
	printBook(book);
	cout << endl;
	return 0;
}

void eraseBook(multimap<string,string> &book,const string & name)
{
	auto pos = book.equal_range(name);
	book.erase(pos.first,pos.second);
}

void printBook(const multimap<string,string> &book)
{
	for(const auto & val:book)
	{
		cout << val.first << "\t" << val.second << endl;
	}
}
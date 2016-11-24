#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <memory>
#include <map>
#include <set>

using namespace std;

bool compare(const string &lhs,const string &rhs)
{
	cout << "compare" << endl;
	return lhs.size() < rhs.size();
}
class test
{
public:
	test():item(compare) {}
	~test() {}

public:
	multiset<string,bool (*) (const string &,const string &) > item;
};

int main(int argc, char const *argv[])
{
	test t;
	t.item.insert("Hello");
	t.item.insert("World");
	return 0;
}
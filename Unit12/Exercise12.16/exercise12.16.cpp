#include <memory>
#include <iostream>
#include <vector>

using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	unique_ptr<int> p(new int(10));	
	cout << *p << endl;
	unique_ptr<int> q(p);
	cout << *q << endl;
	return 0;
}
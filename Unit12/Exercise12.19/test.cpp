#include <memory>
#include <iostream>

using std::shared_ptr;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	shared_ptr<int> sp1;
	shared_ptr<int> sp2;
	cout << ( sp1==sp2 ? "True" : "False" );
	cout << endl;
	return 0;
}
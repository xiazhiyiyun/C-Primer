#include <iostream>
#include <memory>

using std::shared_ptr;
using std::cin;
using std::cout;
using std::endl;

void process(shared_ptr<int> ptr);

int main(int argc, char const *argv[])
{
	process(shared_ptr<int> (new int(10)));
	return 0;
}
	
void process(shared_ptr<int> ptr)
{
	cout << *ptr << endl;
}
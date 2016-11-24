#include <iostream>
#include <memory>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::allocator;

int main()
{
	int n = 4;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string *q = p;
	string word;
	while(cin>>word)
	{
		alloc.construct(q,word);
		q++;
		if(q == p + n)
			break;
	}
	string *r = p;
	while(r != q)
	{
		cout << *r++ << endl;
	}

	r = p;
	while(r != q)
	{
		alloc.destroy(r++);
	}

	alloc.deallocate(p,n);
	return 0;
}
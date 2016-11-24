#include <iostream>
#include <cstdio>

using namespace std;

void fun(int &i)
{
	printf("%p\n", &i);
}

int main(int argc, char const *argv[])
{
	int i = 0;

	printf("%p\n",&i );

	int && j = std::move(i);
	printf("%p\n",&j );
	printf("%d\t%d\n", i,j);
	i = 10;
	printf("%d\t%d\n", i,j);
	// printf("%p\n",&(&i) );
	j = 11;
	printf("%p\n",&j );
	printf("%d\t%d\n", i,j);
	int && k = j *10;
	printf("%p\n",&k );

	fun(i);
	fun(j);
	fun(k);
	cout << "sizeof(allocator<string>)" << sizeof(allocator<string>) << endl;
	cout << "sizeof(string)" << sizeof(string) << endl;

	cout << endl << endl;
	cout << (4 <= 4) << endl;
	cout << (4 <= 4 ) << endl;
	return 0;
}

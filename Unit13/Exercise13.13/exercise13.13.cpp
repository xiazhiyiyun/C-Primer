#include <iostream>
using namespace std;

struct example
{
	example()
	{
		++i;
		cout << "example()" << endl;
	//	cout << "example()" <<　endl;
	}
	~example()
	{
		cout << i << "~example()" << endl;
	}
	example(const example &exam)
	{
		cout << "example(const example &exam)" << endl;
	}
	example &operator=(const example &exam)
	{
		cout << "example &operator=(const example &exam)" << endl;
	}
private:
	static int i; 
};

example fun(example ex)
{
	cout << "example fun(example ex)" << endl;
	return ex;
}

example &funref(example &ex)
{
	cout << "example funref(example &ex)" << endl;
	return ex;
}
int example:: i = 0;
int main()
{

	/*
	 *example()
	 example(const example &exam)
	 example(const example &exam)
	*/
	example a;
	example b = a;
	example c(a);
	cout << "---------------------------\n" << endl; 
	/*
	 * example &operator=(const example &exam)
	 */
	cout << "c = b" <<endl;
	c = b;
	cout << "---------------------------\n" << endl; 

	/*
	 * example(const example &exam)
	 * example fun(example ex)
	 * example(const example &exam)
	 * example &operator=(const example &exam)
	 * ~example()
	 * ~example()
	 */
	cout <<"b = fun(a)" << endl;
	b = fun(a);
	cout << "---------------------------\n" << endl; 

	/*
	 * example(const example &exam)
	 * example fun(example ex)
	 * example(const example &exam)
	 * ~example()
	 * ~example()
	 */
	cout << "example d = fun(b)" << endl;
	example d = fun(b);
	cout << "---------------------------\n" << endl; 

	cout << "example e = funref(b)" <<endl;
	example e = funref(b);
	cout << "---------------------------\n" << endl; 

	/*
	 * ~example()
	 * ~example()
	 * ~example()
	 *
	*/
	cout << "dealer" << endl;
	 
}

#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;

struct connection
{
	
};

struct destination
{
	
};

connection connect(destination *d)
{
	cout << "Creat a connection!" << endl;
	return connection();
}

void disconnection(connection c)
{
	cout << "Disconnect a connection!" << endl;
}

// void end_connection(connection *p)
// {
// 	disconnection(*p);
// }

void f(destination &d)
{
	connection c = connect(&d);
}

void f1(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p( &c,[](connection *p) {disconnection(*p);} );
}

int main(int argc, char const *argv[])
{
	destination d;
	cout << "f(d): " << endl << endl;
	f(d);
	cout << endl;
	cout << "f1(d): " << endl << endl;
	f1(d);
	return 0;
}
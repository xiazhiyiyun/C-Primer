#include <iostream>
#include "Screen.h"
#include "Window_mgr.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Screen myScreen(5,5,'X');
	myScreen.move(4,0).set('#').display(cout);
	cout << endl;
	myScreen.display(cout);
	cout << endl;
	// myScreen.set(4,1,'#').display(cout);
	// cout << endl;

	Window_mgr win;
	win.print(0);
	cout << endl;
	win.clear(0);
	win.print(0);
	cout << endl;
}
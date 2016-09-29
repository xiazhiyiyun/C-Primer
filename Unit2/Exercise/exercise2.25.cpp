#include <iostream>

using namespace std;

int main(){
    
    int ival = 1.01;
    const int &rival1 = 1.01;
    int &rival2 = ival;
    const int &rival3 = 1;

    cout << "ival = " << ival << '\n'
	 << "const &rival1 = " << rival1 << '\n'
	 << "&rival2 = " << rival2 << '\n'
	 << "const &rival3 = " << rival3 << '\n' << endl;
    cout << "---------------------------------------------" << endl;

    rival2 = 3.14159;
    cout << "After rival2 = 3.14159"  << endl;
    cout << "ival = " << ival << '\n'
	 << "const &rival1 = " << rival1 << '\n'
	 << "&rival2 = " << rival2 << '\n'
	 << "const &rival3 = " << rival3 << '\n' << endl;
    cout << "---------------------------------------------" << endl;

    rival2 = rival3;
    cout << "After rival2 = rival3"  << endl;
    cout << "ival = " << ival << '\n'
	 << "const &rival1 = " << rival1 << '\n'
	 << "&rival2 = " << rival2 << '\n'
	 << "const &rival3 = " << rival3 << '\n' << endl;
    cout << "---------------------------------------------" << endl;

    ival = rival3;
    cout << "After ival = rival3"  << endl;
    cout << "ival = " << ival << '\n'
	 << "const &rival1 = " << rival1 << '\n'
	 << "&rival2 = " << rival2 << '\n'
	 << "const &rival3 = " << rival3 << '\n' << endl;
    cout << "---------------------------------------------" << endl;
/*
    rival3 = ival;
    cout << "After rival3 = ival" << endl;
    cout << "ival = " << ival << '\n'
	 << "const &rival1 = " << rival1 << '\n'
	 << "&rival2 = " << rival2 << '\n'
	 << "const &rival3 = " << rival3 << '\n' << endl;
    cout << "---------------------------------------------" << endl;
*/
    return 0;
}

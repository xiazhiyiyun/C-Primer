#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include "date.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;


const vector<string> Date::vec_monthName = {"January","February","March","April","May","June","July ","August","September","October","November","December"};
const vector<string> Date::vec_monthAbbr = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
const vector<int> Date::vec_days         = {31,28,31,30,31,30,31,31,30,31,30,31};
const vector<char> Date::vec_deli        = {'-',' ',',','/'};

int main()
{

	string str("11/1/1990");
	Date date(str);
	cout << date <<endl;
	string str1("Jan 1 1900");
	string str2("February 10,1900");
	Date date2(str2);
	cout << date2 << endl;
	Date date1(str1);
	cout << date1 << endl;
	return 0;
}

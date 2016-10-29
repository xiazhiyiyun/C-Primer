#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

string changeByIns(string src,string start,string end);

int main(int argc, char const *argv[])
{
	
	string name("summer");
	string start("Dr.");
	string end("Jr.");
	string s = changeByIns(name,start,end);
	cout << s << endl;
	return 0;
}

string changeByIns(string src,string start,string end)
{
	src.insert(0," ");
	src.insert(0,start);
	src.append(" ");
	src.append(end);
	return src;
}
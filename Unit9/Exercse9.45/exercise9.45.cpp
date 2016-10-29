#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

string changeToNew(string src,string start,string end);

int main(int argc, char const *argv[])
{
	
	string name("summer");
	string start("Dr.");
	string end("Jr.");
	string s = changeToNew(name,start,end);
	cout << s << endl;
	return 0;
}

string changeToNew(string src,string start,string end)
{
	src.insert(src.begin(),1,' ');
	src.insert(src.begin(),start.begin(),start.end());
	src.append(" ");
	src.append(end);
	return src;
}
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <vector>
#include <utility>

using std::ifstream;
using std::string;
using std::pair;
using std::multimap;
using std::vector;
using std::cin;
using std::endl;
using std::cout;

void add_children(multimap<string,string> & families,const string &family,const string &child);

int main(int argc, char const *argv[])
{
	multimap<string,string> families;
	add_children(families,"zhang","hao");
	add_children(families,"zhang","li");

	for(const auto & elem:families)
	{
		cout << elem.first << " " << elem.second << endl;
	}

	return 0;
}


void add_children(multimap<string,string> & families,const string &family,const string &child)
{
		families.insert({family,child});
}
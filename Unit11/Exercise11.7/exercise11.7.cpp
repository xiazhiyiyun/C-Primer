#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <vector>

using std::ifstream;
using std::string;
using std::back_inserter;
using std::map;
using std::vector;
using std::cin;
using std::endl;
using std::cout;

void add_family(map<string,vector<string>> & families,const string &family );
void add_children(map<string,vector<string>> & families,const string &family,const string &child);

int main(int argc, char const *argv[])
{
	map<string,vector<string>> families;
	add_family(families,"zhang");
	add_children(families,"zhang","hao");
	add_children(families,"zhang","li");
	add_family(families,"su");

	for(const auto & elem:families)
	{
		cout << "family:" << elem.first << "  child: ";
		for(const auto & val:elem.second)
		{
			cout  << val  << " ";
		}
		cout << endl;
	}

	return 0;
}

void add_family(map<string,vector<string>> &families,const string &family )
{
	families[family];
}

void add_children(map<string,vector<string>> & families,const string &family,const string &child)
{
	families[family].push_back(child);
}
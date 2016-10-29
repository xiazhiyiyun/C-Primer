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
using std::back_inserter;
using std::map;
using std::vector;
using std::pair;
using std::make_pair;
using std::cin;
using std::endl;
using std::cout;

void add_family(map<string,vector< pair<string,string> >> & families,const string &family );
void add_children(map<string,vector< pair<string,string> >> & families,const string &family,const pair<string,string> & child);

int main(int argc, char const *argv[])
{
	map<string,vector< pair<string,string> > > families;

	add_family(families,"zhang");
	add_children(families,"zhang",{"hao","1993 08 24"});
	add_children(families,"zhang",make_pair("li","1992 09 14"));
	add_family(families,"su");

	for(const auto & elem:families)
	{
		cout << "family:" << elem.first << "\tchild: ";
		for(const auto & val:elem.second)
		{
			cout << "\t" <<  val.first << " " << val.second ;
		}
		cout << endl;
	}

	return 0;
}

void add_family(map<string,vector< pair<string,string> >> &families,const string &family )
{
	families[family];
}

void add_children(map<string,vector< pair<string,string> >> & families,const string &family,const pair<string,string> & child)
{
	families[family].push_back(child);
}

// void add_children(map<string,vector<string>> & families,const string &family,const string &child)
// {
// 	families[family].push_back(child);
// }
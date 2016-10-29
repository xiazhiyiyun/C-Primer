#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <vector>
#include <set>
#include <list>
#include <sstream>
#include <utility>

using std::ifstream;
using std::istringstream;
using std::string;
using std::back_inserter;
using std::map;
using std::set;
using std::vector;
using std::list;
using std::cin;
using std::endl;
using std::cout;
using std::pair; 

int main(int argc, char const *argv[])
{
	ifstream ifin("pair.file");
	if(!ifin)
	{
		ifin.close();
		return -1;
	}

	string line;
	vector<pair<string,int>> vec_pair;
	while(getline(ifin,line))
	{
		istringstream is(line);
		string word;
		int nu;
		if( is >> word && is >> nu)
		{
			vec_pair.push_back({word,nu});
		}
	}

	ifin.close();	
	for(const auto & val:vec_pair)
	{
		cout << val.first << " " << val.second << endl; 
	}

	return 0;
}


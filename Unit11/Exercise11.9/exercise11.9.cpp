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

string trans(string & word);

int main(int argc, char const *argv[])
{
	ifstream in("word.file");
	if(!in)
	{
		return  -1;
	}

	map<string,list<int>> words;
	string line;
	int linenu = 0P;

	while(getline(in,line))
	{
		linenu++;
		istringstream istr(line);
		string word;

		while(istr >> word)
		{
			string sWord = trans(word);
			words[sWord].push_back(linenu);
		}
	}

	in.close();

	for(const auto &val:words)	
	{
		cout << val.first << ": ";
		for(const auto & nu:val.second)
		{
			cout << nu << " ";
		}
		cout << endl;
	}
	// cout << endl;
	return 0;
}

string trans(string & word)
{
	set<char> notIn{',',';','.','/',':','?'};

	string sWord;
	transform(word.begin(),word.end(),back_inserter(sWord),tolower);

	while( !sWord.empty()  &&  notIn.count(sWord.back()) )
	{
		sWord.pop_back();
		// cout << sWord << endl;
	}
	return sWord;	
}
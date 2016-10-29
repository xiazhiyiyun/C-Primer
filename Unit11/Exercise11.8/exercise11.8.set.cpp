#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <vector>
#include <set>

using std::ifstream;
using std::string;
using std::back_inserter;
using std::map;
using std::set;
using std::vector;
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

	set<string> words;	
	string word;

	while(in >> word)
	{
		string sWord = trans(word);
		words.insert(sWord);
	}

	in.close();

	for(const auto &val:words)	
	{
		cout << val << " ";
	}
	cout << endl;
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
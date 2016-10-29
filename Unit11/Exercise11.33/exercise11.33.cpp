#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <utility>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>

using std::istringstream;
using std::runtime_error;
using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::pair;
using std::vector;
using std::map;

void word_transform(ifstream &map_file,ifstream &input);
void build_map(ifstream &map_file,map<string,string> &map_word);
string transform(const string &word,const map<string,string> &map_word);

int main(int argc, char const *argv[])
{
	ifstream input("input.file");
	ifstream map_file("map.file");
	if(!input || !map_file)
	{
		cout << "Error: cannot open file!" << endl;
	}
	word_transform(map_file,input);
	
	return 0;
}

void word_transform(ifstream &map_file,ifstream &input)
{
	map<string,string> map_word;

	build_map(map_file,map_word);
	string line;
	while(getline(input,line))
	{
		istringstream is(line);
		bool first = true;
		string word;
		while(is >> word)
		{
			if(first)
			{
				first = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word,map_word);
		}

		cout << endl;
	}
}

string transform(const string &word,const map<string,string> &map_word)
{
	auto find = map_word.find(word);
	if(find != map_word.end())
	{
		return find->second;
	}
	return word;
}

void build_map(ifstream &map_file, map<string,string> &map_word)
{
	string key,value;
	while( map_file >> key && getline(map_file,value) )
	{
		if(!key.empty() && !value.empty())
		{
			map_word[key] = value.substr(1);
		}else
		{
			throw runtime_error("no rules for " + key);
		}
	}
}
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

using std::ifstream;
using std::string;
using std::map;
using std::cin;
using std::endl;
using std::cout;

int main(int argc, char const *argv[])
{
	ifstream in("word.file");
	if(!in)
	{
		return  -1;
	}

	map<string,size_t> words;
	
	string word;

	while(in >> word)
	{
		// auto re = words.insert({word,1});
		// if(!re.second)
		// {
		// 	++re.first->second;
		// }

		++words.insert({word,0}).first->second;
	}

	in.close();

	for(auto it = words.begin(); it != words.end(); ++it)
	{
		cout << it->first << " occurs " << it->second << " times!" << endl;
	}
	return 0;
}
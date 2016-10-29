#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char const *argv[])
{
	ifstream in("file.txt");
	if(!in)
	{
		cout << "cannot open file.txt" << endl;
		return -1;
	}

	string ascender("bdhklt");
	string descender("gjpqy");

	string word,result;
	while(in >> word)
	{
		if(word.find_first_of(ascender) == string::npos && word.find_first_of(descender) == string::npos)
		{
			if(word.size() > result.size())
			{
				result = word;
			}
		}
	}

	if(result.empty())
	{
		cout << "Error: no word!" << endl;
	}else
	{
		cout << "result :" << result << endl;
	}
	in.close();
	return 0;
}
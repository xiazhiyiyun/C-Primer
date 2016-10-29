#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

string oldToNewRep(string s,string oldStr,string newStr);

int main(int argc, char const *argv[])
{
	
	string str("tho you are my name,but thru you.");
	cout << str << endl;
	
	string oldStr = "tho";
	string newStr = "though";
	string res = oldToNewRep(str,oldStr,newStr);
	cout << res << endl;
	
	oldStr = "thru";
	newStr = "through";
	res = oldToNewRep(res,oldStr,newStr);
	cout << res << endl;
	
	return 0;
}

string oldToNewRep(string s,string oldStr,string newStr)
{

	if(oldStr.empty())
	{
		return s;
	}

	unsigned i = 0;
	while( i <= s.size() - oldStr.size() )
	{
		unsigned j = i;
		unsigned k = 0;
		while( k < oldStr.size() )
		{
			if( s[j] == oldStr[k] )
			{
				++j;
				++k;
			}else
			{
				break;
			}
		}
		if(k == oldStr.size())
		{
			s = s.replace(i,j-i,newStr);
			// cout << "cout " << s  << endl;
			i = i + newStr.size();
		}else
		{
			++i;
		}
	}
	return s;
}

#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

string oldToNew(string s,string oldStr,string newStr);

int main(int argc, char const *argv[])
{
	
	string str("tho you are my name,but thru you.");
	cout << str << endl;
	
	string oldStr = "tho";
	string newStr = "though";
	string res = oldToNew(str,oldStr,newStr);
	cout << res << endl;
	
	oldStr = "thru";
	newStr = "through";
	res = oldToNew(res,oldStr,newStr);
	cout << res << endl;
	
	return 0;
}

string oldToNew(string s,string oldStr,string newStr)
{
	if(oldStr.empty())
	{
		return s;
	}

	auto iter = s.begin();

	while(iter <= s.end() - oldStr.size())
	{
		auto iter1 = iter;
		auto iter2 = oldStr.begin();
		while(iter2 != oldStr.end() && *iter1 == *iter2)
		{
			++iter1;
			++iter2;
		}
		if(iter2 == oldStr.end())
		{
			auto iter3 = s.erase(iter,iter1);
			iter = s.insert(iter3,newStr.begin(),newStr.end());
			iter = iter + newStr.size();
		}else
		{
			++iter;
		}
	}
	return s;
}
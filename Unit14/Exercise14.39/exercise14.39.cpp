#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class StrLenEqual
{
public:
	StrLenEqual(size_t _sz):sz(_sz) {}
	// void setLen(size_t len) {sz = len;}
	// size_t getLen() {return sz;}

	bool operator()(const string &str) 
	{
		return str.size()==sz;
	}

private:
	size_t sz;
};

class StrLenBetween
{
public:
	StrLenBetween(size_t _min,size_t _max):min(_min),max(_max) {}

	bool operator()(const string &str) 
	{
		return (str.size() >= min) && (str.size() <= max);
	}

private:
	size_t min;
	size_t max;
};

class StrLenGreater
{
public:
	StrLenGreater(size_t _min):min(_min) {}

	bool operator()(const string &str) 
	{
		return str.size() >= min;
	}

private:
	size_t min;
};

int main(int argc, char const *argv[])
{
	ifstream in("word.txt");
	if(!in)
	{
		cout << "Error cannot open file!" << endl;
	}
	string word;
	vector<string> vec;
	while(in >> word)
	{
		vec.push_back(word);
	}

	StrLenBetween strlen1(1,9);
	StrLenGreater strlen2(10);
	int len1,len2;
	len1 = len2 = 0;
	for(const auto &val:vec)
	{
		if(strlen1(val))
			++len1;
		else if(strlen2(val))
			++len2;

	}

	cout << len1 << endl;
	cout << len2 << endl;
	return 0;
}
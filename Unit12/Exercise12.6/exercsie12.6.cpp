#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;

void vecInput(vector<string> *p_vec);
void vecPrint(vector<string> * p_vec);
vector<string> *vecAlloc();

int main(int argc, char const *argv[])
{
	vector<string> *p_vec;
	p_vec = vecAlloc();
	vecInput(p_vec);
	vecPrint(p_vec);
	delete p_vec;
	return 0;
}

vector<string> *vecAlloc()
{
	return new vector<string>();
}

void vecPrint(vector<string> * p_vec)
{
	if(!p_vec)
	{
		throw runtime_error("nullptr");
	}

	for(unsigned i = 0;i < p_vec->size(); ++i)
	{
		cout << (*p_vec)[i] << " ";
	}
	cout << endl;
}

void vecInput(vector<string> *p_vec)
{
	cout << "input the string!" << endl;
	string word;

	if(!p_vec)
	{
		throw runtime_error("nullptr");
	}

	while(cin >> word)
	{
		p_vec->push_back(word);
	}
}
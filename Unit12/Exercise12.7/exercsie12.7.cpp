#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::string;
using std::vector;
using std::runtime_error;

void vecInput(shared_ptr< vector<string> > p_vec);
void vecPrint(shared_ptr< vector<string> > p_vec);
shared_ptr< vector<string> > vecAlloc();

int main(int argc, char const *argv[])
{
	shared_ptr< vector<string> > p_vec;
	p_vec = vecAlloc();
	vecInput(p_vec);
	vecPrint(p_vec);
	// delete p_vec;
	return 0;
}

shared_ptr< vector<string> > vecAlloc()
{
	return make_shared< vector<string> >();
}

void vecPrint(shared_ptr< vector<string> > p_vec)
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

void vecInput(shared_ptr< vector<string> > p_vec)
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
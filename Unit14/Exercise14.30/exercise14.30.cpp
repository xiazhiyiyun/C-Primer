#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "StrBlob.h"
#include "StrBlobPtr.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::weak_ptr;

int main(int argc, char const *argv[])
{
	StrBlob str;

	string word;
	while( cin >> word)	
	{
		str.push_back(word);
	}

	for(auto it = str.begin(); it != str.end(); ++it )
	{
		cout << *it << " ";
	}
	cout << endl;

	StrBlobPtr strPtr(str);
	cout << *strPtr << " " << *(strPtr+2) << endl;
	cout << strPtr->size() << " " << (strPtr+2)->size() << endl;

	return 0;
}


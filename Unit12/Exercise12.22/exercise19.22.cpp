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
	StrBlob str{"hello","world","cin","cout"};

	for(auto it = str.begin(); neq(it,str.end()); it.incr() )
	{
		cout << it.deref() << " ";
	}
	cout << endl;

	// StrBlobPtr strPtr(str);

	return 0;
}


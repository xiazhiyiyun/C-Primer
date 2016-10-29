#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iterator>
#include <fstream>
#include <functional>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;

int main(int argc, char const *argv[])
{
	ifstream in("in.file");
	ofstream odd("odd.file");
	ofstream even("even.file");

	if(!in || !odd || !even)
	{
		cout << "ERROR" << endl;
	}

	istream_iterator<int> is(in),eof;
	ostream_iterator<int> odd_out(odd," ");
	ostream_iterator<int> even_out(even,"\n");

	vector<int> vec(is,eof);

	copy_if(vec.begin(),vec.end(),odd_out,[](int i) {return i&1;});
	// cout << endl;
	copy_if(vec.begin(),vec.end(),even_out,[](int i) {return !(i&1);});
	return 0;
}
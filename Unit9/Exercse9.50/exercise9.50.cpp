#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char const *argv[])
{
	
	std::vector<string> vec_str{"123","124","100","12.12"};	

	double res_int = 0;
	for(const auto &ref:vec_str)
	{
		res_int += stod(ref);
	}

	cout << "res_int: " << res_int << endl;
	return 0;
}


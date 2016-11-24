#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>

// using namespace std;
using namespace std::placeholders;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::greater;
// using std::count_if;
// using std::find_if;
using std::not_equal_to;

int main(int argc, char const *argv[])
{
	vector<int> vec{1,2,3,4,5,6,7,8,1027};
	greater<int> great;
	int num = count_if(vec.begin(),vec.end(),bind(great,_1,1024));
	cout << "num = " << num << endl;

	vector<string> vec_str{"pooh","pooh","hello","world"};
	not_equal_to<string> nequal;
	auto res = find_if(vec_str.begin(),vec_str.end(),bind(nequal,_1,"pooh"));
	cout << *res << endl;

	vector<int> vec_int;
	// transform(vec.begin(),vec.end(),vec.begin(),bind(std::multiplies<int>(),_1,2));
	transform(vec.begin(),vec.end(),back_inserter(vec_int),bind(std::multiplies<int>(),_1,2));

	for(auto val:vec_int)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CompInt
{
public:
	CompInt(int oldval):val(oldval) {}

	bool operator()(int newval)
	{
		if(val == newval)
			return true;
		return false;
	}
private:
	int val;	
};

int main(int argc, char const *argv[])
{	
	CompInt icomp(10);
	vector<int> vec{1,2,10,6,8,10,12};
	
	for(const auto val :vec)
	{
		cout << val << " ";
	}
	cout << endl;
	
	replace_if(vec.begin(),vec.end(),icomp,9);

	for(const auto val :vec)
	{
		cout << val << " ";
	}
	cout << endl;

	return 0;
}
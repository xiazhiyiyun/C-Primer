#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using std::vector;
using std::list;
using std::cout;
using std::endl;

int main()
{
	list<int> lis_int{1,2,3,4,5,6,7,8};
	vector<int> vec_int{0,0,0,0,0,0};

	vector<double> vec_dou1(lis_int.begin(), lis_int.end());
	vector<double> vec_dou2(vec_int.begin(), vec_int.end());

	cout << "In vec_dou1 : " ;
	for(const auto &it:vec_dou1)
	{
		cout << it << " ";
	}

	cout << endl;
	cout << "In vec_dou2 : ";
	for(const auto &it:vec_dou2)
	{
		cout << it << " ";
	}
	cout << endl;

}
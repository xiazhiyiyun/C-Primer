#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    int arr[6] = {1,2,3,4,5,6};
    vector<int> ivec(arr,arr+6);

    for(vector<int>::iterator it = ivec.begin();it != ivec.end();it++)
    {
	int temp = (*it % 2) ? *it * 2 : *it;
	*it = temp;
	cout << *it << endl;
    }
}

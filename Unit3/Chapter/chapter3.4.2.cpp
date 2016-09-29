#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main(){
    vector<int> ivec(a,a+5);


    int find;
    cout << "Please input the number you want to search : ";
    cin >> find;

    //binary search
    vector<int>::iterator it_begin = ivec.begin();
    vector<int>::iterator it_end = ivec.end();
    vector<int>::iterator it_middle =  it_begin + ( it_end - it_begin) / 2;

    while(it_middle != ivec.end() && ( ( *it_middle  ) != find ) )
    {
	if( ( *it_middle )  < find )
	{
	    it_begin = it_middle + 1;
            it_middle =  it_begin + ( it_end - it_begin) / 2;
	}
	else
	{
	    it_end = it_middle;
            it_middle =  it_begin + ( it_end - it_begin) / 2;
	}
    }
    if(it_middle == ivec.end() )
    {
        cout << "Cannot find the number!" << endl;
    }
    else
    {
        cout << "The num you search in " << (it_middle-ivec.begin()) << " of the vector" << endl;
    }
}

#include <iostream>
#include <cstring>
using namespace std;
enum color{red,green,blue};
int main()
{
    int i;
    cout << &i << endl;
    color c;
    c=green;
    cout<<&c<<endl;
}

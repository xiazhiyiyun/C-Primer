#include <iostream>
#include <string>

using namespace std;

class D  
{  
public:  
    void printA()  
    {  
        cout<<"printA"<<endl;  
    }  
    void printB()  
    {  
        cout<<"printB"<<endl;  
    }  
};  

int main(int argc, char const *argv[])
{
    D *d;
    d = nullptr;
    cout << "sizeof(D):" << sizeof(D) << endl;
    d->printA();
    d->printB();
    return 0;
}
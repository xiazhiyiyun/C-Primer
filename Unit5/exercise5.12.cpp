#include <iostream>

using namespace std;

int main()
{
    bool fstatus = false;
    /*
    bool ffstatus = false;
    bool flstatus = false;
    bool fistatus = false;
    */
    char ch;

    int vowcnt ,ffcnt,flcnt,ficnt,othercnt;
    vowcnt = ffcnt = flcnt = ficnt = othercnt =  0;

    while(cin >> ch)
    {
	    switch(ch){

		    case 'a': case 'e': case 'o': case'u':
		     ++vowcnt;
		     break;
		    case 'i':
		     if(fstatus == true) 
			     ++ficnt;
		     else 
			     ++vowcnt;
		     fstatus = false;
		     break;
		    case 'f':
		     if(fstatus == true)
		     {
			++ffcnt;
		     	fstatus = false;
		     }
		     else
			    fstatus = true;
		     break;
		    case 'l' :
		     if (fstatus == true)
			     ++flcnt;
		     fstatus = false;
		     break;
		    default:
		     ++othercnt;
		     fstatus = false;
		     break;
	    }
    }

    cout << "vowcnt = " << vowcnt << "\n"
	 << "ffcnt = " << ffcnt << "\n"
	 << "ficnt = " << ficnt << "\n"
	 << "flcnt = " << flcnt << "\n"
	 << "othercnt = " << othercnt << endl;
}

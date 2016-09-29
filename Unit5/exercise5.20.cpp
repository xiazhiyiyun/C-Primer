#include <iostream>
#include <string>

using namespace std;

int main(){
	string word,lastWord = "";
	while(cin >> word){

		if( lastWord == word ){
			cout << word << "is input in two times." << endl;
			break;
		}
		lastWord = word;
	}
	if(!cin)
	    cout << "All were appear in one times." << endl;
}

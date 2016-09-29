#include <vector>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int main(){
	string str;
	vector<string> svec;
	while( cin >> str ){
		svec.push_back(str);
	}
	for(vector<string>::size_type i = 0;i != svec.size();i++ ){
		for(string::size_type j = 0;j < svec[i].size();j++)
		{
			svec[i][j] = toupper(svec[i][j]);
		}
	}

	for(vector<string>::size_type i = 0;i != svec.size(); i++){
		cout << svec[i] << " ";
	}
	cout << endl;
	return 0;
}

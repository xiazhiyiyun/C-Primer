#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main() {
	bitset<32> bs;
	int iarr[7] = {1,2,3,5,8,13,21};
	for(int i = 0;i < 7;i++){
		bs.set( iarr[i] );
	}
	cout << bs << endl;

	string str(32,'0');
	for(int i = 0;i < 7;i++){
		str[str.size() -1 - iarr[i]] = '1';
	}
	cout << str << endl;
	bitset<32> bs1(str);
	cout << bs1 << endl;

	unsigned long ul = bs.to_ulong();
	cout << ul << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
		cout << "Please input the number: ";
		vector<int> ivec;
		int j;
		while (cin >> j) {
			ivec.push_back(j);
							
		}
		vector<int>::size_type i = 0;
		for (; i + 1 < ivec.size(); ++i) {
			cout << ( ivec[i] + ivec[++i] )<< " ";
									
		}
		if (ivec.size() % 2 != 0) {
			cout << ivec[i] << endl;
		        cout << "其中最后一个元素没有求和。" << endl;

		}
		else {
			cout << endl;
								
		}
		cout << "----------------------------------" << endl;
			
		for ( i = 0; i < (ivec.size() / 2); i++ ) {
					cout << ivec[i] + ivec[ivec.size() - 1 - i] << " ";
						
		}

		if (ivec.size() % 2 != 0) {
			cout << ivec[i] << endl;
					
			cout << "其中中间一个元素没有求和。" << endl;
								
		}
		else
			cout << endl;
		return 0;
}

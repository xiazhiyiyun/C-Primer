#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	
    const int size = 6;
    string score[6] = {"F","D","C","B","A","A++"};
    vector<string> scores(score,score+size);

    int sco;
    while(cin >> sco)
    {

    string letterScore = ( (sco < 60) ? scores[0]:scores[(sco - 50) / 10] );
    letterScore += ( (sco != 100 && sco >= 60 ) ? ( ( sco % 10 < 3 ) ? "-" :(sco % 10 > 7 ? "+" : "")): "" );
    cout << letterScore <<endl;
    }   
}

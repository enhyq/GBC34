#include <iostream>
#include <vector>


using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);

    // 6 <-> 9

    int room_no;
    cin >> room_no;
    
    vector<int> V(10, 0);

    while(room_no>0) {
        V[room_no%10]++;
        room_no /= 10;
    }

    // get 6 and 9
    if((V[6] + V[9])%2 == 1) V[6] = (V[6] + V[9])/2 + 1;
    else V[6] = (V[6] + V[9])/2;
    V[9] = 0;

    // find max
    int max = 0;
    for(int i=0; i<9; i++) {
        if(V.at(i) > max) max = V.at(i);
    }

    cout << max << '\n';


    return 0;
}
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N;

    int t;
    vector<int> v;

    // 모든 pos와 neg 숫자들은 합쳐서 넣는다
    bool pos_streak = true;
    int s = 0;
    for(int i=0; i<N; i++) {
        cin >> t;
        if(t>=0){ // pos input
            if(pos_streak) s += t;
            else {
                pos_streak = !pos_streak;
                if(s) v.push_back(s);
                // s = t;
                s = 0;
                v.push_back(t);
            }
        }
        else { // neg input
            if(!pos_streak) {
                v.push_back(t);
                // s += t;
            }
            else {
                pos_streak = !pos_streak;
                if(s) v.push_back(s);
                s = t;
            }
        }
    }
    if(s) v.push_back(s);

    // neg 숫자 합치면 안된다

    // debug
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << '\n';


    return 0;
}
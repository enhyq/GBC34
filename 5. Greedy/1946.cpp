#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T; // T(1 ≤ T ≤ 20)
    int N;

    vector<pair<int, int> > v;
    int a, b, count=0;
    while(T--) {
        cin >> N; // N(1 ≤ N ≤ 100,000)
        int max_a, max_b;
        for(int i=0; i<N; i++) {
            cin >> a >> b;
            if(a==1) max_b = b;
            if(b==1) max_a = a;
            v.push_back(make_pair(a, b));
        }

        // a, b 어느 둘중 하나가 다른 a, b 보다 작지 않은 것 
        // ???
        // 일단 풀기
        for(int i=0; i<N; i++) {
            if(v[i].first <= max_a && v[i].second <= max_b){
                count++;
            }
        }

        cout << count << endl;

        v.clear();
        count=0;
    }

    return 0;
}
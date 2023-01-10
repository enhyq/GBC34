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

    while(T--) {
        // initialize 
        v.clear();

        cin >> N; // N(1 ≤ N ≤ 100,000)

        for(int i=0, a, b; i<N; i++) {
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }

        sort(v.begin(), v.end());

        int max = v[0].second;
        int count = 1;
        
        for(int i=1; i<N; i++) {
            if(v[i].second < max) {
                max = v[i].second;
                count++;
                if(max == 1) break;
            }
        }

        cout << count << endl;
    }

    return 0;
}
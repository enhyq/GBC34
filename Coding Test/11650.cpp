#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// typedef struct t_point {
//     int x, y;
// } point;

// bool compare(point a, point b) {
//     if(a.x > b.x) return true;
//     else if (a.x == b.x) {
//         if(a.y > b.y) return true;
//     }
//     return false;
// }

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int> > V;
    int x, y;
    for(int i=0; i<N; i++) {
        cin >> x >> y;
        V.push_back(make_pair(x, y));
    }

    sort(V.begin(), V.end());

    for(int i=0; i<N; i++) {
        cout << V[i].first << " " << V[i].second << '\n';
    }

    return 0;
}
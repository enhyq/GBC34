#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N;

    queue<int> Q;
    for(int i=0; i<N; i++) {
        Q.push(i+1);
    }

    int i=0, last;
    while(!Q.empty()) {
        last = Q.front();
        if(i%2 == 0) {
            // drop
            Q.pop();
        } else {
            // to bottom
            Q.push(Q.front());
            Q.pop();
        }
        i++;
    }

    cout << last << endl;

    return 0;
}
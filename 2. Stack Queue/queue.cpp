#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    queue<int> Q;

    Q.push(3);
    Q.push(4);
    Q.push(5);

    while(!Q.empty()) {
        int k = Q.front();
        cout << k << '\n';
        Q.pop();
    }

    return 0;
}
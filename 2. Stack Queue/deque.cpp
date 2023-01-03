#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    deque<int> dQ;

    dQ.push_front(3);
    dQ.push_front(4);
    dQ.push_back(2);

    while(!dQ.empty()) {
        int k = dQ.front();
        cout << k << '\n';
        dQ.pop_front();
    }

    return 0;
}
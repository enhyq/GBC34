#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N;

    stack<int> S;

    int n;
    while(N--) {
        cin >> n;
        if(n) S.push(n);
        else S.pop();
    }

    int sum = 0;
    while(!S.empty()) {
        sum += S.top();
        S.pop();
    }

    cout << sum << '\n';

    return 0;
}
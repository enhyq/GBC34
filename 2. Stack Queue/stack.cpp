#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    stack<int> s;

    s.push(3);
    s.push(4);
    s.push(5);

    while(!s.empty()) {
        int k = s.top();
        cout << k << '\n';
        s.pop();
    }

    int arr[10] = {0, };


    return 0;
}
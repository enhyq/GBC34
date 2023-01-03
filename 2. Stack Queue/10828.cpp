#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int cmd_cnt;
    cin >> cmd_cnt;
    
    stack<int> S;
    string cmd;
    int val;

    while(cmd_cnt--){
        // push, pop, empty, size, top
        cin >> cmd;
        if(cmd == "push"){
            cin >> val;
            S.push(val);
        } else if(cmd == "pop") {
            if(S.empty()) cout << -1 << '\n';
            else {
                cout << S.top() << '\n';
                S.pop();
            }
        } else if(cmd == "size") {
            cout << S.size() << '\n';
        } else if(cmd == "empty") {
            cout << S.empty() << '\n';
        } else if(cmd == "top") {
            if(S.empty()) cout << -1 << '\n';
            else cout << S.top() << '\n';
        } else {
            // this case does not exist in this problem
        }
    }

    return 0;
}
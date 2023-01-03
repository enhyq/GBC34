#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int cmd_cnt;
    cin >> cmd_cnt;

    queue<int> Q;
    int val;
    string cmd;

    while(cmd_cnt--){
        cin >> cmd;
        // push pop size empty front back
        if(cmd == "push"){
            cin >> val;
            Q.push(val);
        } else if(cmd == "pop"){
            if(Q.empty()) cout << -1 << '\n';
            else{
                cout << Q.front() << '\n';
                Q.pop();
            }
        } else if(cmd == "size"){
            cout << Q.size() << '\n';
        } else if(cmd == "empty"){
            cout << Q.empty() << '\n';
        } else if(cmd == "front"){
            if(Q.empty()) cout << -1 << '\n';
            else cout << Q.front() << '\n';
        } else if(cmd == "back"){
            if(Q.empty()) cout << -1 << '\n';
            else cout << Q.back() << '\n';
        }

    }
    
    return 0;
}
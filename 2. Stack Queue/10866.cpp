#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);

    int cmd_cnt;
    cin >> cmd_cnt;

    deque<int> dQ;
    string cmd;
    int val;

    while(cmd_cnt--){
        cin >> cmd;
        if(cmd == "push_front"){
            cin >> val;
            dQ.push_front(val);
        } else if(cmd == "push_back"){
            cin >> val;
            dQ.push_back(val);
        } else if(cmd == "pop_front"){
            if(dQ.empty()) cout << -1 << '\n';
            else{
                cout << dQ.front() << '\n';
                dQ.pop_front();
            }
        } else if(cmd == "pop_back"){
            if(dQ.empty()) cout << -1 << '\n';
            else{
                cout << dQ.back() << '\n';
                dQ.pop_back();
            }
        } else if(cmd == "size"){
            cout << dQ.size() << '\n';
        } else if(cmd == "empty"){
            cout << dQ.empty() << '\n';
        } else if(cmd == "front"){
            if(dQ.empty()) cout << -1 << '\n';
            else cout << dQ.front() << '\n';
        } else if(cmd == "back"){
            if(dQ.empty()) cout << -1 << '\n';
            else cout << dQ.back() << '\n';
        } else {
            // 문제에는 해당 조건 불필요
        }
    }

    return 0;
}
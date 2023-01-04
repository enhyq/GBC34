#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int T; // number of test cases
    cin >> T;

    string ps;
    while(T--) {
        stack<char> S;
        cin >> ps;
        for(int i=0; i<ps.length(); i++) {
            if(ps[i]=='(') S.push('(');
            else if(!S.empty() && ps[i]==')') S.pop();
            else {
                S.push(')');
                break;
            }
        }
        if(S.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}
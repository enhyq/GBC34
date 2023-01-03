#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);

    int num;
    cin >> num;

    // consecutive numbers are increasing order
    // if it is decreasing order, then diff must be 1

    stack<int> S;
    string op_odr = "";
    int n;

    cin >> n;

    int i = 1;
    while(1) {
        S.push(i++);
        op_odr.append("+\n");

        while(!S.empty() && S.top() == n) {
            op_odr.append("-\n");
            S.pop();
            if(S.empty() && i == num+1) break;
            cin >> n;
        }
        
        if(i == num+1){
            int size = S.size();
            // cout << "size: " << size << '\n';
            while(--size > 0) cin >> n;
            break;
        }
    }
    
    if(S.empty()) cout << op_odr;
    else cout << "NO" << '\n';


    return 0;
}
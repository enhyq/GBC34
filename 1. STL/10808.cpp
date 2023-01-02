#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;

    vector<int> V(26, 0);

    for(int i=0; i<s.length(); i++) {
        V[s[i]-97]++;
    }

    for(auto iter=V.begin(); iter != V.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << '\n';

    return 0;
}
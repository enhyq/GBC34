#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    // 0 ~ 1001 test cases 
    // each word is <1000 chars
    int test;
    cin >> test;
    
    string s1, s2;
    bool possible;
    while(test--){
        // initialize
        vector<int> a(26,0);
        possible = true;
        cin >> s1;
        cin >> s2;

        if(s1.length() != s2.length()) possible =false;
        else {
            for(int i=0; i<s1.length(); i++) a[s1[i]-97]++;
            for(int i=0; i<s2.length(); i++) {
                if(a[s2[i]-97] == 0) {
                    possible = false;
                    break;
                }
                a[s2[i]-97]--;
            }
        }

        if(possible) cout << "Possible";
        else cout << "Impossible";
        cout << '\n';
    }


    return 0;
}
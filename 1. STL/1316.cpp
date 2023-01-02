#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    string s;
    int group_word_count = 0;
    cin >> n;
    while(n--) {
        cin >> s;
        vector<bool> V(26, false);
        char prev_c = 0;
        bool is_group_word = true;
        for(int i=0; i<s.length(); i++) {
            if(prev_c == s[i]) continue;
            if(V[s[i]-97]) {
                is_group_word = false;
                break;
            }
            V[s[i]-97] = true;
            prev_c = s[i];
        }
        if(is_group_word) group_word_count++;
    }

    cout << group_word_count << '\n';

    return 0;
}
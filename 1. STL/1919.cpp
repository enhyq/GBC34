#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    // 2 words input
    // each < 1000 letters & all lowercase
    int i, sum;
    string s;
    vector<int> a_cnt_1(26, 0);
    vector<int> a_cnt_2(26, 0);

    cin >> s;
    for(i=0; i<s.length(); i++) a_cnt_1.at(s[i]-97)++;
    cin >> s;
    for(i=0; i<s.length(); i++) a_cnt_2.at(s[i]-97)++;

    for(i=0; i<26; i++) a_cnt_1.at(i) = abs(a_cnt_1.at(i) - a_cnt_2.at(i));
    sum = 0;
    for(i=0; i<26; i++) sum += a_cnt_1.at(i);
    
    cout << sum << '\n';

    return 0;
}
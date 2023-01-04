#include <iostream>
#include <cstring>

using namespace std;

int recursion(const char *s, int l, int r, int *cnt) {

    (*cnt)++;

    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, cnt);
}

int isPalindrome(const char *s, int *cnt) {
    return recursion(s, 0, strlen(s)-1, cnt);
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int T; // <= 1000
    cin >> T;

    char str[1001]; // <= 1000

    int cnt;

    while(T--) {
        cin >> str;
        cnt = 0;
        cout << isPalindrome(str, &cnt) << " " << cnt << endl;
    }

    return 0;
}
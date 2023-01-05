#include <iostream>

using namespace std;

void print_recur(char s[][1025], int n, char c, int &w) {
    if(n==0) {
        // 모두 출력한다
        for(int i=0; i<w; i++) {
            for(int j=0; j<w-i; j++) {
                cout << s[i][j];
            }
            // cout << '.';
            if(i!=w-1) cout << '\n';
        }
    }
    else {
        // 가로로 이어 붙인다
        for(int i=0; i<w; i++) {
            for(int j=0; j<w-i; j++) {
                s[i][j+w] = s[i][j];
            }
        }
        // 세로로 이어 붙인다
        for(int i=0; i<w; i++) {
            for(int j=0; j<w-i; j++) {
                s[i+w][j] = s[i][j];
            }
        }

        w *= 2;
        print_recur(s, n-1, c, w);
    }
}

void print_func(int n, char c){
    char s[1024][1025] = {' ', }; // max size
    
    // 초기화!!
    for(int i=0; i<1024; i++) {
        for(int j=0; j<1025; j++) {
            s[i][j] = ' ';
        }
    }

    s[0][0] = c;
    int w = 1;
    print_recur(s, n, c, w);
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    print_func(t, '*');
    cout << '\n';

    // Q. loop안에서 recursion으로 출력하면 잘 안된다..?

    return 0;
}
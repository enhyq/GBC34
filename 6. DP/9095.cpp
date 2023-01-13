#include <iostream>

using namespace std;

// max 11
int m[12] = {1, 1, 2, };

int main(void) {

    // m[n][0][0] will always exist for all numbers

    int t;
    cin >> t;

    for(int i=3; i<12; i++) {
        if(m[i] == 0) m[i] = m[i-3] + m[i-2] + m[i-1];
    }    
    
    while(t--) {
        int n;
        cin >> n;
        cout << m[n] << endl; 
    }

    return 0;
}
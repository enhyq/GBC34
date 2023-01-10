#include <iostream>

using namespace std;

unsigned long long m[91] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, };

int main(void) {
    int N;
    cin >> N;
    // 0 ~ max 90
    
    for(int i=18; i<=N; i++) {
        m[i] = m[i-1] + m[i-2];
    }

    cout << m[N] << endl;

    return 0;
}
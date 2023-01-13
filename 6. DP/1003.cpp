#include <iostream>

using namespace std;

int m0[41] = {1, 0, 1,};
int m1[41] = {0, 1, 1,};

void fibonacci(int n) {
    if (n == 0) {
        // printf("0");
        // return 0;
        return;
    } else if (n == 1) {
        // printf("1");
        // return 1;
        return;
    } else {
        // m0[n-1] m0[n-2]가 둘 다 존재한다면 어떤 계산을 해야 할까
        if(m0[n-1] == 0) fibonacci(n-1);
        if(m0[n-2] == 0) fibonacci(n-2);
        m0[n] = m0[n-1] + m0[n-2];
        m1[n] = m1[n-1] + m1[n-2];
        // return fibonacci(n-1) + fibonacci(n-2);
        return;
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    // need to count function calls for each of fibo(0) and fibo(1)
    int T;
    cin >> T;
    while(T--) {
        int n; // 0 <= n <= 40
        cin >> n;
        fibonacci(n);
        cout << m0[n] << " " << m1[n] << endl;
    }


    return 0;
}
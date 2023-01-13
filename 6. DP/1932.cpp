#include <iostream>

using namespace std;

int t[2][500];
// 18 16 15
// 10 15

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    int size;
    cin >> size;

    int val;
    // 이건 bottom-up 방식: 초기 값 부터 시작해서 내가 원하는 지점까지 계산한다
    for(int i=0; i<size; i++) {
        for(int j=0; j<=i; j++) {
            cin >> val;
            // i%2 번째를 max를 저장하는 배열로 사용한다
            // 다른 배열에는 이전 max 값이 저장되어 있다

            // 첫번째와 마지막 입력은 max비교를 하지 않아도 된다
            if(j==0) t[i%2][0] = t[! (i%2)][0] + val;
            else if(j==i) t[i%2][j] = t[! (i%2)][j-1] + val; // 이전에 저장된 max값은 개수가 하나 더 적다
            else {
                // 세모의 중간 값은 max를 비교해서 구해야 한다
                t[i%2][j] = max(t[! (i%2)][j-1], t[! (i%2)][j]) + val;
            }
        }
    }

    val = t[! (size%2)][0];
    for(int i=1; i<size; i++) {
        if(val < t[! (size%2)][i]) val = t[! (size%2)][i];
    }
    cout << val << endl;

    return 0;
}
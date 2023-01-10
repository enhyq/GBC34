#include <iostream>

using namespace std;

int m[1000001] = {0, 0, 1, 1, };

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N;

    // 이 문제에서 DP인 거슬 찾는 방법
    // X 가 주어졌을 때 /3, /2, -1 3가지가 모두 가능한데 이 경우에서 최적을 경우를 찾는 것이기 때문에 DP 또는 greedy를 활용해야 함을 알 수 있다


    // bottom-up approach
    for(int i=4; i<=N; i++) {
        if(i%3==0) m[i] = m[i/3] + 1;
        if(i%2==0) m[i] ? min(m[i], m[i/2]+1) : m[i/2]+1;
        m[i] = m[i] ? min(m[i], m[i-1]+1) : m[i-1]+1; // N == 1인 경우 아예 for문을 돌지 않기 때문에 상관 없다
    }

    cout << m[N] << endl;

    return 0;
}

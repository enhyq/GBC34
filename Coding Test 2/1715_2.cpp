#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    // freopen("input_1715.out", "r", stdin);

    int N, n;
    cin >> N;

    priority_queue<int> pq;
    stack<long long> s;

    for(int i=0; i<N; i++) {
        cin >> n;
        if(N == 1) {
            cout << 0 << '\n';
            return 0;
        }
        pq.push(-n);
    }

    int sum = 0;
    while(pq.size()>1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sum += -(a+b);
        pq.push(a+b);
    }

    cout << sum << endl;

    return 0;
}
// 8% 에서 계속 틀린다..
// 무엇이 잘못 되었을까?
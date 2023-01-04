#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    deque<int> dQ;

    int n, m; // n: total number of elements, m: number of elements to extract
    cin >> n >> m;

    // 1 ~ n
    for(int i=0+1; i<=n; i++) dQ.push_back(i);

    int k, inst=0;
    while(m--){
        cin >> k; // element to take out
        // 다 left로 돌리고 만약 n/2보다 조금 움직였으면
        int t_inst = 0;
        while(dQ.front() != k) {
            dQ.push_back(dQ.front());
            dQ.pop_front();
            t_inst++;
        }
        // cout << t_inst << endl; // debug
        
        if(t_inst <= (n/2)) inst += t_inst;
        else inst += n-t_inst; // n/2가 아님
        
        dQ.pop_front();
        n--;
    }

    cout << inst << '\n';

    return 0;
}
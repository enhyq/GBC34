#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    freopen("input_1715.out", "r", stdin);
    
    int N;
    cin >> N;
    
    vector<int> v;
    vector<unsigned long long> t;

    //input
    int temp;
    for(int i=0; i<N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    
    if(N==1) {
        // 카드 묶음이 하나면 비교할 필요가 없기 때문에 0 출력
        cout << 0 << endl;
        return 0;
    }

    // 입력 받은 카드 묶음 크기를 오름차 순으로 정렬
    sort(v.begin(), v.end());

    // 계산 패턴을 맞추기 위해 t에 v의 처음 값 넣어주기
    t.push_back(v[0]);
    for(int i=1; i<v.size(); i++) {
        // 이전 카드 묶음 크기 + 현재 카드 묶음 크기
        t.push_back(t[i-1]+v[i]);
    }

    // debug
    // for(int i=0; i<v.size(); i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    // for(int i=0; i<t.size(); i++) {
    //     cout << t[i] << " ";
    // }
    // cout << endl;

    unsigned long long sum = 0;
    for(int i=1; i<t.size(); i++) {
        sum += t[i];
    }

    cout << sum << endl;

    return 0;
}
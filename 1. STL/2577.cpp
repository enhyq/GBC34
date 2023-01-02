#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    // 100 ~ 1000 사이 정수 A,B,C 곱한 결과에 사용된 0~9 숫자 개수 순서대로 출력
    // 1000^3 = 1x10^9 인데 int max는 최대 2x10^9 때문에 int형 사용해도 됨
    int A, B, C, product;
    cin >> A >> B >> C;
    product = A * B * C;

    // cout << product << endl; // debug

    vector<int> V(10, 0);

    while(product>0){
        V[product%10]++;
        product /= 10;
    }

    for(auto iter=V.begin(); iter != V.end(); iter++) {
        cout << *iter << '\n';
    }

    return 0;
}
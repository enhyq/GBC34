#include <iostream>
#include <map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    map<int, int> m;

    m.insert(make_pair(2,3));
    m.insert(make_pair(1,5));
    m.insert(make_pair(8,9));
    // m.insert({8,1}); // c++ 버전이 충분히 높다면

    // Index로도 접근 가능하다
    m[3] = 5;

    // auto 사용시 iter 선언 생략 가능
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << ' ' << iter->second << '\n';
    }
    cout << '\n';



    return 0;
}
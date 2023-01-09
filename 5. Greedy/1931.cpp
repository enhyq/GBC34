#include <iostream>
#include <algorithm>

using namespace std;


pair<int, int> arr[100000];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr+N);

    int count = 1, pre_end = arr[0].second;
    int idx = 0;
    for(int i=1; i<N; i++) {
        // cout << "curr: " << arr[i].first << "," << arr[i].second << endl;
        // cout << "pre_end: " << pre_end << endl;

        // 만약에 새로운 시작 시간 저장된 끝 시간 보다 크거나 같으면
        // 새로운 시작 시간 이전의 시간대에는 저장된 끝 시간이 가장 효율적이다는 의미
        // 
        if(arr[i].first >= pre_end) {
            // debug
            // cout << "(" << arr[idx].first << "," << arr[idx].second << ") " << endl;

            idx = i;
            count++;
            pre_end = arr[i].second;
        } else {
            // 
            if(arr[i].second < pre_end) {
                idx = i;
                pre_end = arr[i].second;
            }
        }

        // cout << "---" << endl;
    }
    // cout << "(" << arr[idx].first << "," << arr[idx].second << ") ";
    // cout << endl;

    cout << count << endl;

    return 0;
}
/*

8
1 3
2 3
3 3
3 6
4 4
5 5
6 6
7 7


*/
// 13 33 44 55 66 77
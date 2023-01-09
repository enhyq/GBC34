#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N;
    vector<int> A, B;
    
    int n, i, sum=0;
    for(i=0; i<N; i++) {
        cin >> n;
        A.push_back(n);
    }
    for(i=0; i<N; i++) {
        cin >> n;
        B.push_back(n);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for(i=0; i<N; i++) sum += A[i] * B[i];

    cout << sum << endl;


    return 0;
}
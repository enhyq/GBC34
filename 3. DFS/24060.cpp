#include <iostream>
// #include <vector>

using namespace std;

void merge(int *A, int *tmp, int p, int q, int r, int &k, int &cnt, int &k_save) {
    int i = p, j = q+1, t = 1;
    // vector<int> tmp;
    // tmp.resize(A.size());
    while(i <= q && j <= r) {
        if(A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    while(i<=q) tmp[t++] = A[i++];
    while(j<=r) tmp[t++] = A[j++];
    i = p; t = 1;
    while(i<=r) {
        if(cnt++ == k) k_save = tmp[t];
        A[i++] = tmp[t++];
    }
}

void merge_sort(int *A, int *tmp, int p, int r, int &k, int &cnt, int &k_save) {
    if(p<r) {
        int q = (p+r)/2;
        merge_sort(A, tmp, p, q, k, cnt, k_save);
        merge_sort(A, tmp, q+1, r, k, cnt, k_save);
        merge(A, tmp, p, q, r, k, cnt, k_save);
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;

    // vector<int> A;
    // A.push_back(0); // to begin from index 1
    int A[500002];
    int tmp[500002];
    
    int input;
    // while(n--) {
    //     cin >> input;
    //     A.push_back(input);
    // }
    for(int i=1; i<=n; i++) {
        cin >> input;
        A[i] = input;
    }
    int k_save, cnt=1;
    merge_sort(A, tmp, 1, n, k, cnt, k_save);
    
    if(k > cnt-1) k_save = -1;
    cout << k_save << '\n';

    // for(auto i = A.begin()+1; i != A.end(); i++) {
    //     cout << *(i) << " ";
    // }
    // cout << '\n';

    return 0;
}
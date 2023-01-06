#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    vector<int> V;
    int N, M, n, m;
    
    cin >> N;
    
    while(N--) {
        cin >> n;
        V.push_back(n);
    }

    sort(V.begin(), V.end()); // sort in ascending order. Ex) 1,2,3,4

    int size = V.size();
    cin >> M;

    while(M--) {
        cin >> m;

        int low=0, high=size-1, mid;
        bool found = false;
        // binary search
        while(low<=high) {
            mid = (low+high)/2;
            if(V[mid] == m) {
                found = true;
                break;
            }
            if(m < V[mid]) high = mid-1;
            else low = mid+1;
        }

        cout << found << '\n';
    }

    return 0;
}
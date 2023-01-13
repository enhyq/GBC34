#include <iostream> 
#include <vector>

#define SIZE 100000

using namespace std;

int arr[SIZE];
int m[SIZE];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    m[0] = arr[0];

    for(int i=1; i<n; i++) {
        m[i] = max(m[i-1]+arr[i], arr[i]);
    }

    int max = -1000;
    for(int i=0; i<n; i++) {
        if(m[i] > max) max = m[i];
    }

    cout << max << endl;


    return 0;
}
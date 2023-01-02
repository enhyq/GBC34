#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);

    // range is from -100 to 100 (inclusive)
    vector<int> V(201, 0);
    
    int n, t;
    cin >> n;
    
    while(n--) {
        cin >> t;
        V[t+100]++;
    }

    cin >> n;
    cout << V[n+100] << endl;
    
    return 0;
}
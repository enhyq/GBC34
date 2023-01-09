#include <iostream>

using namespace std;

int main(void) {
    // 1 1 2 2 2 8
    // 6

    int need[6] = {1,1,2,2,2,8};

    int n;
    for(int i=0; i<6; i++) {
        cin >> n;
        cout << n - need[i] << " ";
    }
 
    return 0;
}
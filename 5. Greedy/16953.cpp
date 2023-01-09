#include <iostream>

using namespace std;

int main(void) {
    
    int a, b, count=0;
    cin >> a >> b;
    while(1) {
        if(b%10 == 1) {
            b /= 10;
            count++;
        }
        else if(b%2 == 0) {
            b /= 2;
            count++;
        }
        else {
            cout << -1 << endl;
            return 0;
        }
        
        if(a == b) break;
        if(b <= a) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << count+1 << endl;

    return 0;
}
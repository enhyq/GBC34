#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);




    return 0;
}
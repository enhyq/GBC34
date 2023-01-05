#include <iostream>
#include <algorithm>
#define SIZE 10

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int arr[SIZE] = {16, 35, 52, 20, 71, 82, 41, 100, 94, 68};

    sort(arr, arr + SIZE);

    int left = 0, right = SIZE-1;
    int find_element = 52;
    while(left <= right) {
        int mid = (left+right)/2;

        if(arr[mid] > find_element) right = mid;
        else right = mid;
    }

    return 0;
}
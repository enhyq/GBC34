#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int star, space, num;
    cin >> num;

    star = num*2-1;
    space = 0;
    for(star; star>1; star-=2, space++)
        cout << string(space,' ') << string(star, '*') << '\n';
    for(star; star<=num*2-1; star+=2, space--)
        cout << string(space,' ') << string(star, '*') << '\n';

    return 0;
}
#include <iostream>
#include <set>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<int> s;

    s.insert(3);
    s.insert(4);
    s.insert(6);

    s.insert(1);

    set<int>::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++){
        cout << *iter << ' ';
    }
    cout << '\n';


    return 0;
}
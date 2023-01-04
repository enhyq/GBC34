#include <iostream>
#include <string>

using namespace std;

string concat_str(string &s1, string &s2) {
    // concat string line by line
    
}

void print_recur(int n, string s) {
    
    if(n==0) cout << s;
    else{
        s += s;
        s += "\n";
        s += s;
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    // previous output is put 3 times for the next one


    return 0;
}
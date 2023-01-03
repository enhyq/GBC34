#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v;
    int i = 1;
    while(i <= n) {
        v.push_back(i++);
    }

    vector<int>::iterator iter = v.begin()-1;
    cout << "<";

    bool start = true;

    while(!v.empty()) {
        if(!start) cout << ", ";
        start = false;

        for(int i=0; i<k-1; i++) {
            iter++;
            if(iter == v.end()) iter = v.begin();
        }
        if(iter+1 == v.end()) {
            cout << *(v.begin()); // print
            v.erase(v.begin());
            iter = v.end()-1; // !!!
        }
        else{
            cout << *(iter+1); // print
            v.erase(iter+1);
        }
    }
    cout << ">" << '\n';

    return 0;
}
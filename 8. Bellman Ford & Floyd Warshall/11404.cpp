#include <iostream>
#include <vector>
#include <climits>

#define SIZE 101
// INT_MAX = 2147483647
#define INF INT_MAX

using namespace std;
//      from   to
long long city[SIZE][SIZE];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, e;
    cin >> n >> e;

    // initialize 2d array
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) continue; //0
            city[i][j] = INF;
        }
    }

    // get input
    for(int i=0, a, b, c; i<e; i++) {
        cin >> a >> b >> c;
        if(city[a][b]) {
            if(c < city[a][b]) city[a][b] = c;
        }
        else city[a][b] = c;
    }

    // debug print
    // cout << "---" << endl;
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout << city[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    // Floyd Warshall
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                // if(!city[i][k] || !city[k][j]) continue;
                if(city[i][j] > city[i][k] + city[k][j]) city[i][j] = city[i][k] + city[k][j];
            }
        }
        // debug print
        // cout << "---" << endl;
        // for(int i=1; i<=n; i++) {
        //     for(int j=1; j<=n; j++) {
        //         cout << city[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
    }


    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(city[i][j] == INF) cout << 0 << " ";
            else cout << city[i][j] << " ";
        }
        cout << '\n';
    }



    return 0;
}
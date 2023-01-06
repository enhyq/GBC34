#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define SIZE 25

using namespace std;

bool map[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dr[4] = {0, 1, 0,-1};
int dc[4] = {1, 0,-1, 0};

int BFS(int r, int c, int M, int N) {
    queue<pair<int, int> > Q;
    Q.push(make_pair(r, c));
    visited[r][c] = true;

    int nr, nc, count=1;
    while(!Q.empty()) {
        r = Q.front().first;
        c = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];
            if(nr<0 || nr>M-1 || nc<0 || nc>N-1) continue;

            if(!visited[nr][nc] && map[nr][nc]) {
                Q.push(make_pair(nr, nc));
                visited[nr][nc] = true;
                count++;
            }
        }
    }
    
    return count;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int MN; // square
    cin >> MN;

    char line[MN+1];
    for(int i=0; i<MN; i++) {
        cin >> line;
        for(int j=0; j<MN; j++) {
            if(line[j]=='0') map[i][j] = 0;
            else map[i][j] = 1;
        }
    }

    int count=0;
    vector<int> V;
    for(int i=0; i<MN; i++) {
        for(int j=0; j<MN; j++) {
            if(!visited[i][j] && map[i][j]) {
                V.push_back(BFS(i, j, MN, MN));
                count++;
            }
        }
    }

    sort(V.begin(), V.end());

    cout << count << '\n';
    for(auto iter=V.begin(); iter != V.end(); iter++) {
        cout << *(iter) << '\n';
    }
    

    return 0;
}
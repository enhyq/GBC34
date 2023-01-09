#include <iostream>
#include <queue>

#define SIZE 1001

using namespace std;

int dr[4] = {0, 1, 0,-1};
int dc[4] = {1, 0,-1, 0};

int tomatoes[SIZE][SIZE]; // 4byte * 1000 * 1000 = 4mb
queue<pair<int, int> > Q; // 최대 1000*1000개 element * (각 pair 8 byte + 2 pointer link 16 byte) = 24,000,000 bytes =  24mb


int q_size = 0;

void BFS(int R, int C) {
    int r, c;
    int nr, nc;

    while(!Q.empty()) {
        r = Q.front().first;
        c = Q.front().second;
        Q.pop();
        for(int i=0; i<4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];

            if(nr<0 || nr>R-1 || nc<0 || nc>C-1) continue;
            // || tomatoes[nr][nc] > tomatoes[r][c]
            if(tomatoes[nr][nc] == 0) {
                tomatoes[nr][nc] = tomatoes[r][c] + 1;
                Q.push(make_pair(nr,nc));
                if(Q.size() > q_size) q_size = Q.size(); // debug
            }
        }
    }
}

int main(void) {
    // ios::sync_with_stdio(false); cin.tie(0);

    freopen("../input.txt", "r", stdin);

    int R, C;
    cin >> C >> R; // 2 <= M,N <= 1000

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            scanf("%d", &tomatoes[i][j]);

        }
    }
    
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(tomatoes[i][j] == 1)
                Q.push(make_pair(i,j));
        }
    }

    BFS(R, C);
    

    // debug print
    int max = 1;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(tomatoes[i][j] > max) max = tomatoes[i][j];
            else if(tomatoes[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            // printf("%d ", tomatoes[i][j]);
        }
        // printf("\n");
    }
    cout << max-1 << endl;

    cout << q_size << endl;


    return 0;
}
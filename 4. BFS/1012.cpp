#include <iostream>
#include <queue>

#define SIZE 50

using namespace std;

bool map[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dr[4] = {0, 1, 0,-1};
int dc[4] = {1, 0,-1, 0};

void BFS(int r, int c, int max_r, int max_c) {
    queue<pair<int, int> > Q;
    // Q.push({r, c});
    Q.push(make_pair(r, c));
    visited[r][c] = true;

    while(!Q.empty()) {
        r = Q.front().first;
        c = Q.front().second;

        Q.pop();
        int nr, nc;

        for(int i=0; i<4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];

            if(nr<0 || nr>max_r-1 || nc<0 || nc>max_c-1) continue;

            if(!visited[nr][nc] && map[nr][nc]) {
                visited[nr][nc] = true;
                // Q.push({nr, nc});
                Q.push(make_pair(nr, nc));
            }
        }
    }
}

void print_map(int M, int N) {
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(visited[i][j]) cout << "*" << " ";
            else cout << map[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int T; 
    cin >> T;

    int M, N, K;
    // 1 <= M <= 50         M -> row
    // 1 <= N <= 50         N -> col
    // 1 <= K <= 2500

    int count, n, m;

    while(T--) {

        cin >> M >> N >> K;

        for(int i=0; i<K; i++) {
            cin >> n >> m;
            map[n][m] = true;
        }

        // print_map(M, N);

        count = 0; // init count
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(!visited[i][j] && map[i][j]) {
                    BFS(i, j, M, N);
                    count++;
                    // print_map(M, N);
                }
            }
        }

        cout << count << '\n';
        
        // re-init
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                map[i][j] = false;
                visited[i][j] = false;
            }
        }
    }

    return 0;
}
#include <iostream>
#include <queue>

#define SIZE 500

using namespace std;

bool map[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0,-1,  0};

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
                visited[nr][nc] = true;
                count ++;
                Q.push(make_pair(nr, nc));
            }
        }
    }

    return count;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int M, N; // M = rows; N = cols;
    cin >> M >> N;

    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    int count=0, max_size=0, size;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[i][j] && map[i][j]){
                size = BFS(i, j, M, N);
                if(size > max_size) max_size = size;
                count++;
            }
        }
    }
    
    cout << count << '\n' << max_size << '\n';
   

    return 0;
}
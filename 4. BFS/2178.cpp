#include <iostream>
#include <vector>
#include <queue>

#define SIZE 101

using namespace std;

int dx[4] = {-1, 0, 1,  0};
int dy[4] = { 0, 1, 0, -1};
int MAP[SIZE][SIZE];
int value[SIZE][SIZE];
int R, C;


void BFS() {
    queue<pair<int, int> > Q;
    Q.push({0, 0});     // (0,0) 좌표에서 시작한다
    value[0][0] = 1;

    while(!Q.empty()) {
        // Current
        pair<int, int> curr = Q.front();
        int curr_y = curr.first;
        int curr_x = curr.second;
        Q.pop();

        // Finish
        if(curr_y == R-1 && curr_x == C-1) {
            cout << value[R-1][C-1] << '\n';
            break;
        }

        // 주변 탐색, 동서남북 4방향
        for(int k=0; k<4; k++) {
            int nx = curr_y + dx[k];
            int ny = curr_x + dy[k];
            
            // 바깥으로 안나가게 하기 위해
            if(nx<1 || nx>=C || ny<1 || ny>=R) continue;

            // MAP에서 값 1인 것만 이동할 수 있도록,
            if(MAP[ny][nx] == 0 || value[ny][nx] != 0) continue;
            // 다음 위치
            value[ny][nx] = value[curr_y][curr_x] + 1;
            Q.push({nx, ny});
        }

        // for(int i=01; i<=R; i++) {

        // }
    }
}


int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> R >> C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> MAP[i][j];
        }
    }

    BFS();

    return 0;
}
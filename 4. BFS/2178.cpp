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
    // Q.push({0, 0});     // (0,0) 좌표에서 시작한다
    Q.push(make_pair(0,0));
    value[0][0] = 1;

    while(!Q.empty()) {
        // Current
        pair<int, int> curr = Q.front();
        int curr_x = curr.first;
        int curr_y = curr.second;
        Q.pop();

        // Finish
        if(curr_y == R-1 && curr_x == C-1) {
            cout << value[R-1][C-1] << '\n';
            break;
        }

        // 주변 탐색, 동서남북 4방향
        for(int k=0; k<4; k++) {
            int nx = curr_x + dx[k];
            int ny = curr_y + dy[k];
            
            // 바깥으로 안나가게 하기 위해
            if(nx<0 || nx>=C || ny<0 || ny>=R) continue;

            // MAP에서 값 1인 것만 이동할 수 있도록,
            if(MAP[ny][nx] == 0 || value[ny][nx] != 0) continue;

            // 다음 위치
            value[ny][nx] = value[curr_y][curr_x] + 1; // value에 계속 1을 더해준다 -> value에 따라갈 수 있는 길이 만들어진다
            // Q.push({nx, ny});
            Q.push(make_pair(nx, ny));
        }
    }
}


int main(void) {
    // ios::sync_with_stdio(false); cin.tie(0);

    cin >> R >> C;
    for (int i=0 ; i<R ; i++) { 
        for (int j=0 ; j<C ; j++) { 
            scanf("%1d", &MAP[i][j]) ; 
        }
    }
    // char line[C];
    // for(int i=0; i<R; i++) {
    //     cin >> line;
    //     for(int j=0; j<C; j++) {
    //         if(line[j] == '0') MAP[i][j] = 0;
    //         else MAP[i][j] = 1;
    //     }
    // }

    // cout << endl;
    // for(int i=0; i<R; i++) {
    //     for(int j=0; j<C; j++) {
    //         cout << MAP[i][j];
    //     }
    //     cout << endl;
    // }
    
    BFS();

    return 0;
}
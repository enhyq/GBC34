#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define SIZE 1001

using namespace std;

vector<int> graph[SIZE];
bool visited[SIZE]; // global variable is initialized to false(0);

void DFS(int start) {
    

    visited[start] = true;
    cout << start << " ";

    for(int i=0; i<graph[start].size(); i++) {
        int next = graph[start][i];
        if(!visited[next]) DFS(next);
    }
}


void BFS(int start) {
    queue<int> Q;
    Q.push(start);
    visited[start] = true;

    while(!Q.empty()) {
        start = Q.front();
        Q.pop();

        cout << start << " ";

        for(int i=0; i<graph[start].size(); i++) {
            int next = graph[start][i];
            if(!visited[next]) {
                Q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int N, M, V;
    cin >> N >> M >> V;

    for(int i=0, a, b; i<M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0; i<N; i++) {
        // 정점 번호가 1부터 시작하기 때문에 N번째 정점의 network까지 정렬을 해줘야 한다
        sort(graph[i+1].begin(), graph[i+1].end());
    }

    DFS(V);
    cout << '\n';
    for(int i=0; i<SIZE; i++) visited[i] = false; // re-inits
    BFS(V);
    cout << '\n';

    return 0;
}
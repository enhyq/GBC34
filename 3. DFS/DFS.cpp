#include <iostream>
#include <vector>

using namespace std;

int N, M, V;
vector<int> graph[10001];
bool visited[10001];

void DFS(int start) {
    if( visited[start] ) return ;  // if not yet visited

    visited[start] = true;
    cout << start << ' ';

    for(int i=0; i<graph[start].size(); i++){
        int next_node = graph[start][i];
        if( !visited[next_node]) {
            DFS(next_node);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    // N - 컴퓨터의 수 (node)
    // M - 연결된 컴퓨터의 쌍 수 (edge)
    // V - 시작 지점
    cin >> N >> M >> V;

    for(int i=0, a, b; i<M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(V);

    return 0;
}
#include <iostream>
#include <vector>

#define SIZE 101

using namespace std;

vector<int> graph[SIZE];
bool visited[SIZE];

void DFS(int start, int &count) {
    // start node가 방문되지 않았다는 조건이 있다면 아래 확인은 필요 없다
    // if( visited[start] ) return;

    visited[start] = true;

    // do something
    count++;
    
    for(int i=0; i<graph[start].size(); i++) {
        int next = graph[start][i];
        if(!visited[next]) {
            DFS(next, count);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int N, P; // N - number of nodes; P - number of pairs
    cin >> N >> P;

    for(int i=0, a, b; i<P; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int count = 0;
    DFS(1, count);
    cout << count-1 << '\n'; // -1 to exclude the first one

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

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

    while(!Q.empty()) {
        for(int i=0; i<graph[start])
    }

    visited[start] = true;
    

}
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

#define INF INT_MAX
#define SIZE 20001

using namespace std;
vector<pair<int, int> > graph[20001];
int D[SIZE];

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    D[start] = 0;
    pq.push(make_pair(0, start)); // cumulative weight, node

    int node, weight, next_node, next_weight;
    while(!pq.empty()) {
        node = pq.top().second;
        weight = -pq.top().first;
        pq.pop();

        // calculate weight for all the neighboring nodes
        for(int i=0; i<graph[node].size(); i++) {
            next_node = graph[node][i].first;
            next_weight = graph[node][i].second;

            if(D[next_node] > weight + next_weight) {
                D[next_node] = weight + next_weight;
                pq.push(make_pair(-(weight + next_weight), next_node));
            }

        }
    }
    
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int V, E, start; 
    cin >> V >> E >> start; 

    for(int i=1; i<=V; i++) {
        D[i] = INF;
    }

    for(int i=0, a, b, c; i<E; i++) {
        cin >> a >> b >> c;
        // 단방향
        graph[a].push_back(make_pair(b,c));
    }

    dijkstra(start);

    for(int i=1; i<=V; i++) {
        if(D[i] == INF) cout << "INF" << '\n';
        else cout << D[i] << '\n';
    }
    

    return 0;
}

/*

5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6

*/
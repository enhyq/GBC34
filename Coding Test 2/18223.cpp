#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF INT_MAX
#define SIZE 5001

using namespace std;

vector<pair<int, int> > graph[SIZE];
int dist[SIZE];

// 선언 순서 중요
int V, E, P;

void dijkstra(int start) {
    // initialize dist and vertex to INF
    for(int i=1; i<=V; i++) {
        dist[i] = INF;
    }

    // start from 1
    dist[start] = 0;

    priority_queue<pair<int, int> > pq; // weight, node
    pq.push(make_pair(0, start));


    int node, weight, next_node, total_weight;
    while(!pq.empty()) {
        node = pq.top().second;
        weight = -pq.top().first;
        pq.pop();

        for(int i=0; i<graph[node].size(); i++) {
            next_node = graph[node][i].first;
            total_weight = weight + graph[node][i].second;
            if(dist[next_node] > total_weight) {
                dist[next_node] = total_weight;
                pq.push(make_pair(-total_weight, next_node));
            }
        }
    }

}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    // freopen("input_18223.out", "r", stdin);

    cin >> V >> E >> P;
    
    for(int i=0, a, b, c; i<E; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c)); // node, weight
        graph[b].push_back(make_pair(a, c));
    }

    // 1 ~ P까지 거리 + P ~ V까지 거리
    // 1 ~ V까지 거리와 같은지 확인

    dijkstra(1);
    
    int dist_to_dst = dist[V];
    int dist_to_p = dist[P];

    dijkstra(P);
    int dist_from_p_to_dst = dist[V];

    if(dist_to_p == INF || dist_from_p_to_dst == INF) {
        cout << "GOOD BYE" << endl;
    }
    else {
        if((dist_to_p + dist_from_p_to_dst) == dist_to_dst) cout << "SAVE HIM" << endl;
        else cout << "GOOD BYE" << endl;
    }

    return 0;
}


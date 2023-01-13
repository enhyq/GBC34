#include <iostream>
#include <queue>
#include <climits>
#include <vector>

#define SIZE 801
#define INF INT_MAX

using namespace std;

vector<pair<int, int> > graph[SIZE];
int D[SIZE];

int dijkstra(int start, int end, int size) {
    priority_queue<pair<int, int> > pq;
    for(int i=0; i<=size; i++) D[i] = INF; // initialize

    pq.push(make_pair(0, start)); // {weight, node}
    D[start] = 0;

    int node, weight, next_node, total_weight;
    while(!pq.empty()) {
        node = pq.top().second;
        weight = -pq.top().first;
        pq.pop();

        for(int i=0; i<graph[node].size(); i++) {
            next_node = graph[node][i].first;
            total_weight = graph[node][i].second + weight;
            
            if(D[next_node] > total_weight ) {
                D[next_node] = total_weight;
                pq.push(make_pair(-total_weight, next_node));
            }
        }
        
    }
    if(D[end] == INF) return -1;
    return D[end];
}


int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    freopen("1504_input.out", "r", stdin);

    int N, E;
    cin >> N >> E;
    for(int i=0, a, b, c; i<E; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    int v1, v2;
    cin >> v1 >> v2;
    // start 1
    // go through v1
    // go through v2
    // end N
    int total_d_1=0, total_d_2=0, d;


    d = dijkstra(1, v1, N);
    if(d == -1) {
        total_d_1 = d;
    } else {
        total_d_1 += d;
        d = dijkstra(v1, v2, N);
        if(d == -1) {
            total_d_1 = d;
        } else {
            total_d_1 += d;
            d = dijkstra(v2, N, N);
            if(d == -1) {
                total_d_1 = d;
            } else {
                total_d_1 += d;
            }
        }
    }

    d = dijkstra(1, v2, N);
    if(d == -1) {
        total_d_2 = d;
    } else {
        total_d_2 += d;
        d = dijkstra(v2, v1, N);
        if(d == -1) {
            total_d_2 = d;
        } else {
            total_d_2 += d;
            d = dijkstra(v1, N, N);
            if(d == -1) {
                total_d_2 = d;
            } else {
                total_d_2 += d;
            }
        }
    }
    
    if(total_d_1 == INF && total_d_2 == INF) cout << -1 << endl;
    else if (total_d_1 == INF) cout << total_d_2 << endl;
    else if (total_d_2 == INF) cout << total_d_1 << endl;
    else cout << min(total_d_1, total_d_2) << endl;

    return 0;
}
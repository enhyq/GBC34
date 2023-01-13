#include <iostream>
#include <queue>
#include <vector>
#include <climits>

#define INF INT_MAX
#define SIZE 1001

using namespace std;

vector<pair<int, int> > graph[SIZE];
int vertex[SIZE]; // 0 is undefined
int dist[SIZE];

int N, M;

void dijkstra(int start) {
    // initialize dist
    for(int i=1; i<=N; i++) {
        dist[i] = INF;
    }
    // initialize vertex
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start)); // weight, node;
    dist[start] = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();

        int next_node, total_weight;
        for(int i=0; i<graph[node].size(); i++) {
            next_node = graph[node][i].first;
            total_weight = graph[node][i].second + weight;

            if(dist[next_node] > total_weight) {
                dist[next_node] = total_weight;
                vertex[next_node] = node;
                pq.push(make_pair(-total_weight, next_node));
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    freopen("input_2211.out", "r", stdin);

    cin >> N >> M;
    for(int i=0, a, b, c; i<M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    dijkstra(1);

    int cnt = 0;
    for(int i=2; i<=N; i++) if(vertex[i]) cnt++;
    cout << cnt << endl;

    for(int i=N; i>=2; i--) {
        if(vertex[i]!=0) cout << i << " " << vertex[i] << '\n';
    }


    return 0;
}
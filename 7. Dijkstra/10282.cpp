#include <iostream>
#include <queue>
#include <vector>
#include <climits>

#define SIZE 10001
#define INF INT_MAX

using namespace std;

vector<pair<int, int> > graph[SIZE];
int D[SIZE];

int n, d, c;

void dijkstra(int start) {
    // initialize D
    for(int i=1; i<=n; i++) D[i] = INF;
    // cout << "[";
    // for(int i=1; i<=n; i++) cout << D[i] << " ";
    // cout << "]" << endl;
    priority_queue<pair<int, int> > pq;
    D[start] = 0;
    pq.push(make_pair(0, start)); // -weight, node

    int node, weight, next_node, total_weight;
    while(!pq.empty()) {
        node = pq.top().second;
        weight = -pq.top().first;
        pq.pop();
        // 인접 노드 개수만큼 돌린다
        for(int i=0; i<graph[node].size(); i++) {
            next_node = graph[node][i].first; // 다음 노드
            total_weight = graph[node][i].second + weight; // 다음 노드 까지의 weight
            if(total_weight < D[next_node]) {
                pq.push(make_pair(-total_weight, next_node)); // pq에 추가
                D[next_node] = total_weight;
                // pq를 쓰는 이유는 덮어 쓰는 computation을 최소화 하기 위해서 (내 생각)
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;

    freopen("input_10282.out", "r", stdin);

    cin >> T;
    while(T--) {
        cin >> n >> d >> c;
        for(int i=1; i<=n; i++) {
            graph[i].clear();
        }
        for(int i=0, a, b, s; i<d; i++) {
            cin >> a >> b >> s;
            // a 는 b에 의존한다
            // b 가 감염되면 s초 이후에 a 또한 감염된다
            graph[b].push_back(make_pair(a, s));
        }
        dijkstra(c);
        int max = 0, count = 0;
        // cout << "("; // debug
        for(int i=1; i<=n; i++) {
            // debug
            // if(D[i] == INF) cout << "INF" << " ";
            // else cout << D[i] << " ";

            if(D[i] != INF ) {
                count++; // 이동 가능한 노드는 모두 감염된 컴퓨터이기 때문에 count를 센다
                // 감염 되는데 걸리는 시간을 구하는 것이기 때문에
                // 가장 오래 걸리는 노드를 찾는 것이다
                if(D[i] > max) max = D[i];
            }
        }
        // debug
        // cout << ")" << endl;
        
        cout << count << " " <<  max << '\n';
    }

    return 0;
}
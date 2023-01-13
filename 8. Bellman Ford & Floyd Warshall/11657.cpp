#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define SIZE 501
#define INF __LONG_LONG_MAX__

using namespace std;

long long dist[SIZE]; // underflow가 발생하기 때문에 long long으로 설정해줘야 한다
vector<pair<pair<int, int>, int> > edges;
int N, E;

bool flag;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    // initialize
    for(int i=0; i<SIZE; i++) dist[i] = INF;

    // freopen("input_11657.out", "r", stdin);

    cin >> N >> E;
    for(int i=0, a, b, c; i<E; i++) {
        cin >> a >> b >> c;
        edges.push_back({{a,b},c});
    }
    // 입력에서 같은 도시로 가는 노선이 여러개 존재 할 수도 있다

    // start from 1
    dist[1] = 0;

    for(int i=0; i<N; i++) {

        for(int j=0; j<edges.size(); j++) {
            int s = edges[j].first.first;
            int e = edges[j].first.second;
            int d = edges[j].second;

            if(dist[s] != INF && dist[e] > dist[s]+d) {
                if(i == N-1) {
                    flag = true;
                    break;
                }
                dist[e] = dist[s] + d;
            }
        }
    }
    
    if(flag){
        cout << -1 << endl;
        return 0;
    }

    // print
    for(int i=2; i<=N; i++) {
        if(dist[i] == INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}
# Dijkstra

 - 최단 경로 탐색 알고리즘
     - 두 꼭짓점 간의 가장 짧은 경로를 찾는 알고리즘이다

조건: 
 - 가중치는 양수이어야 한다

## 알고리즘
 - 우선순위 큐를 사용 하는 방법과 그렇지 않는 방법이 있다

### 우선순위 큐 사용하는 방법

 ```cpp
function Dijkstra(Graph, source):
    dist[source] ← 0  // 초기화

    create vertex set Q

    for each vertex v in Graph:
        if v ≠ source
            dist[v] ← INFINITY // 소스에서 v까지의 아직 모르는 길이
            prev[v] ← UNDEFINED   // v의 이전 노드

        Q.add_with_priority(v, dist[v])

    while Q is not empty:    // 메인 루프
        u ← Q.extract_min()  // 최고의 꼭짓점을 제거하고 반환한다
        for each neighbor v of u: // Q에 여전히 남아 있는 v에 대해서만
            alt ← dist[u] + length(u, v)
            if alt < dist[v]
                dist[v] ← alt
                prev[v] ← u
                Q.decrease_priority(v, alt)

    return dist, prev
 ```

 1. 시작 노드의 dist는 0 다른 모든 노드의 dist는 INF로 초기화 한다
 2. Priority Queue에 시작 노드와 거리를 추가한다
    - PQ는 거리 오름차 순으로 정렬되도록 한다
 3. PQ에 값이 있으면 가장 작은 값을 가진 노드u를 빼고 4번을 진행. 없으면 종료한다.
 4. 가장 작은 값이 있던 노드u의 주변 노드 v에 대해서 u의 dist값과 u-v의 거리를 더한 값이 v의 dist 값보다 적은지 확인한다.
 5. 더 적다면 dist값을 4단계에서 계산한 값으로 바꾸고 PQ에 해당 노드와 그 dist값을 추가한다

 - prev 배열을 사용하면 최소 거리 뿐만 아니라, 최소 거리를 얻기 위해 거쳐야 하는 중간 노드 경로를 얻을 수 있다

# DFS
 > Depth First Search

 > "깊이 우선 탐색"

 - tree 나 graph 형태의 데이터 구조를 순회 하는데 사용되는 알고리즘이다

 - **backtracking**으로 다시 위로 되돌아 오기 전에 최대한 멀리 들어가는 방법이다

 - 한번 방문한 노드는 visitied 배열에 저장 하게 된다
 
 - **backtracking**으로 되돌아 오면서 방문하지 않은 **node**를 발견하게 되면 해당 노드로 다시 최대한 멀리 간다

 - pseudo code:
    ```python
        DFS(node):
        if node is null:
            return
        visit(node)
        mark node as visited
        for each child c of node:
            if c is not visited:
            DFS(c)
    ```

 - 그래프를 배열 형태로 표현 가능하다 (2D array)

![graph example](https://static.javatpoint.com/ds/images/bfs-vs-dfs.png)


| node | connected node |
| - | - |
| 0 | 1,3 |
| 1 | 0,2,3,5,6 |
| 2 | 1,3,4,5 |
| 3 | 0,1,2,4 |
| 4 | 2,3,6 |
| 5 | 1,2 |
| 6 | 1,4 |


 - DFS는 시작 노드의 정보가 필요하다

 - 그리고 node 개수만큼의 크기의 visited 정보를 담는 boolean type의 배열이 필요하다
     - 해당 배열을 false(0)으로 초기화 하고
     - 예를 들어 1번 째 노드를 방문했다면 visited 배열의 1번째 element값을 true로 바꾼다
     - 이렇게 하면 다음에 1번째 노드를 방문 했는지 확인하기 위해서는 visited 배열의 1번째 위치만 확인하면 되기 때문에 상당히 효율적이다

 - 시작 노드를 0으로 잡으면
     - 0 -> 1 -> 2 -> 3 -> 4 -> 6
     - 이렇게 방문하게 되고
     - **backtracking**으로 다시 시작 노드로 되돌아 오면서 인접 node중에 아직 방문하지 않은 노드가 있는지 확인한다
     - 0 -> 1 -> 2 로 돌아 왔을 때 아직 5를 방문한 적이 없기 때문에 5로 들어간다
     - 이후 0으로 되돌아 오고 더 이상 방문하지 않은 인접 node가 없기 때문에 DFS는 종료된다

 - 실제 코드 예시
 ```cpp
    int N, M, V;

    vector<int> graph[10001];
    bool visited[10001];

    void DFS(int start) {
        if( visited[start] ) return ;
  
        cout << start << ' ';
        visited[start] = true;

        for(int i=0; i<graph[start].size(); i++){
            int next_node = graph[start][i];
            if( visited[next_node]) {
                DFS(next_node);
            }
        }
    }
 ```

 - 위에 실제 예시의 경우는 배열로 정리된 형태의 node를 방문하기 때문에 null인지 확인 할 필요는 없다
 - pseudo code에서 visite(node) 부분은 실제 예시에서 해당 노드의 값을 출력하는 일을 한다
 - 나머지는 뭐 똑같다


 - 위에는 recursion으로 구현되어 있는데
 - stack을 사용해서 iterative하게 구현 할 수 도 있다

 - 양방향 vs 단방향
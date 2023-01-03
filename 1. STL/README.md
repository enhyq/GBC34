# STL

## C++ 기초

더 빠른 input을 위해 추가해 줘야 하는 코드
```c++
    ios::sync_with_stdio(false);
    cin.tie(0);
```

## STL 기초
### Vector

 - `#include <vector>`

 - index로 접근 가능한 형태로 정보를 저장한다 - 배열

 - iterator를 사용해서 접근 할 수도 있다
```c++
    vector<int> V;
    ...

    vector<int>::iterator iter;
    for(iter=V.begin(); iter != V.end(); iter++){
        cout << *iter << ' ';
    }
```

### Set

`#include <set>`

같은 값을 하나 밖에 가질 수 없다
오름차순으로 정렬된다

Vector에서 사용한 것과 같이 Iterator를 사용해서 각 element에 접근 가능하다

정렬되지 않은 set을 원한다면 `unordered_set`을 사용할 수 있다.


### Map
 - 내부적으로 **Red Black Tree**를 사용한다

 - key-value pair의 형태를 가진다

 - [] operator 를 사용해서 key-value를 업데이트 하거나 추가 할 수 있다

    ```c++
        M['key'] = 5;
    ```
 - iterator를 사용해 각 element에 접근할 수 있다
 - map 선언 및 초기화 예시

 ```cpp
    map<string, int> m{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
    map<string, int> m(make_pair("CPU", 10), make_pair("GPU", 15), make_pair("RAM", 20));
 ```
  - erase()
    - `m.erase("GPU");` : key 값으로 삭제
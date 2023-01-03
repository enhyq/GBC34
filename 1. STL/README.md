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

 - index로 접근 가능한 형태로 정보를 저장한다 - 배열과 같다
 - 다만 배열과는 다른게 size가 필요에 맞게 자동으로 커지거나 줄어든다
    

#### Member Functions

 - iterator를 사용해서 접근 할 수도 있다
    - `begin()` : return iterator to beginning
    - `end()` : return iterator to end

    ```c++
        vector<int> V;
        ...

        vector<int>::iterator iter;
        for(iter=V.begin(); iter != V.end(); iter++){
            cout << *iter << ' ';
        }
    ```
 - Capacity 관련
    - `size()`
    - `resize()`
    - `capacity()`
    - `empty()` : checks if empty
    - `shrink_to_fit()`
 - Element access
    - operator`[]`
    - `at()`
    - `front()`
    - `back()`
    - `data()` : returns pointer to the memory array used internally
 - Modifiers
    - `assign()`
        - `assign(InputIterator first, InputIterator last);`
        - `assign(n, val);`
    - `push_back()`
    - `pop_back()`
    - `insert()`
        - `insert(position, val);`
    - `erase()`
        - `erase(position);`
        - `erase(const_iterator first, const_iterator last);`
    - `swap()` : swap contents with another vector
        - `swap(vector& x);`
    - `clear()` : clear content -> size becomes 0
    - `emplace()` : 중간에 끼워 넣기
        - `emplace(const_iterator position, Args&&... args);`

더 자세히 보기:
 - https://cplusplus.com/reference/vector/vector/

### `const` review
 - `const int a` : 선언 이후에 a의 값 변경 불가능

### Set

`#include <set>`

 - element의 값 자체가 key이고 유일해야 한다
 - element의 값은 변경 불가능 하지만 추가하거나 삭제할 수 있다
오름차순으로 정렬된다

 - 

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
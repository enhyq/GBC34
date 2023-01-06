# Sort

C++ 에서 제공하는 sort함수를 사용하고 싶으면 `algorithm`라이브러리를 추가해야 한다
```cpp
#include <algorithm>
```

 - 기본적으로는 오름차순으로 정렬된다

 - compare 함수를 직접 정의 할 수 있다

 - 내림차 순으로 정렬하고 싶다면 내장되어 있는 compare함수를 사용할 수 있다
     - `std::greater<int>()`
 - 직접 만드는 compare 함수
     - boolean type을 반환해야 한다
    ```cpp
    bool compare(int a, int b) {
        if( a > b ) return true;
    }
    ```

# Binary Search

 - 
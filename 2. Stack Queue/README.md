# Stack
 - **LIFO** (Last In First Out)
 - 마지막에 들어온게 가장 먼저 나온다
    - FILO 인지 LIFO인지 헷갈리면 *First Out*에 초점을 맞춘다고 생각하기!
 - 
## Methods
 - top() : 가장 위에 있는 값을 반환한다
   - does not check whether the stack if empty or not
 - pop() : 가장 위에 있는 값을 제거한다
   - does not check whether the stack if empty or not
 - empty() : 1 if empty, 0 if not empty
 - push()
 - size()
 - emplace()
 - swap()

# Queue
 - **FIFO** (First In First Out)
## Methods
 - empty() : 1 if empty else 0
 - size() : returns size
 - front() : returns reference to next(aka "oldest") element
   - does not check if Q is empty
 - back() : returns reference to last(aka "newest") element
   - does not check if Q is empty
 - push() 
 - emplace()
 - pop() : removes next element
   - does not check if Q is empty
 - swap()

# Deque
 - stack 과 queue의 특징을 모두 가지고 있다
 - 앞뒤가 뚤려있다 (양방향으로 들어오고 나갈 수 있다)
 - 


# C++ 꿀팁
 - 전역 변수는 0으로 초기화 된다
 ```cpp
   ...

   int ARR[10][10]; // values are initialized to 0
   
   int main() {
      ...
   }
 ```
## Initialization
 - Initialize with Declaration
   - `int arr[10] = {0, };`
 - memset
   - can initialize to 0
   - ` memset(arr, 0, sizeof(arr)); `
 - fill
   - 

## d
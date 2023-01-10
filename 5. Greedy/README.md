# Greedy Algorithm

 - **local optimization**

 - 순간 순간 최적의 결과를 따라간다

 - DP = "global optimization"

 - 각 단계에서 지역 최적의 선택을 하고 전체 최적의 해답을 찾는 알고리즘 패러다임이다
 
     - 한 순간에 제일 좋아보이는 선택을 하고, 이 선택이 미치는 영향에 대해서는 신경쓰지 않는다

     - 항상 전체 최적의 해답을 찾을 것은 아니다

     - 일반적으로 효율적이고 구현이 쉽다

예시)
당신이 편의점 알바라고 해보자 어떤 손님에게 돈을 거슬러 줄 때 동전 밖에 줄 수 없는데 항상 최소의 동전 개수를 거슬러 줘야 한다고 하자.
 - 500, 100, 50, 10 동전이 있고
 - 4100원을 거슬러 줘야 한다면
 - 가장 단위가 큰 500원을 4개 주고, 그다음 단위인 100원을 거슬러 줄 것이다

 ```cpp
    #include <iostream>
    using namespace std;

    const int NUM_COINS = 4;
    int coins[NUM_COINS] = {10, 50, 100, 500};

    int main() {
        int amount;
        cin >> amount;

        int numCoins = 0;
        // 가장 큰 동전부터 시작
        for (int i = NUM_COINS - 1; i >= 0; i--) {
            while (amount >= coins[i]) {
                amount -= coins[i];
                numCoins++;
            }
        }
        cout << numCoins << endl;

        return 0;
    }

 ```
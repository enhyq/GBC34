#include <iostream>
#include <vector>
#include <string>

using namespace std;

// time limit is 1 seconds 
// there are 1 ~ 100,000 test cases
// 0 ~ 100,000 number of elements
// + need to parse the numbers 

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;

    string command;
    int size;
    string list;

    while(T--) {
        // cout << "command: ";
        cin >> command;
        // cout << "size : ";
        cin >> size;
        // cout << "list: ";
        cin >> list;

        int list_size = list.size();
        int front=1, back=list_size-1;
        bool is_rev = false, error_flag = false;

        for(int i=0; i < command.length(); i++) {
            if(command[i] == 'D') {
                if(is_rev) back -= 2;
                else front += 2;

                if(front-1 > back) {
                    // error case
                    error_flag = true;
                    break;
                }

                if(is_rev) { 
                    if(list[back] != '[') {
                        // while(list[back] != '[' || list[back] != ',') back--;
                        // 위의 코드를 사용하면 segmentation fault가 뜬다... why?
                        // && 를 써야 한다
                        while(1) {
                            if(list[back] == '[') break; 
                            if(list[back] == ',') break;
                            back--;
                        }
                    }
                } else {
                    if(list[front-1] != ']') {
                        while(1) {
                            if(list[front-1] == ',') break;
                            if(list[front-1] == ']') break;
                            front++;
                        }
                    }
                }
            
            } else if (command[i] == 'R') is_rev = !is_rev;
        }
        // cout << "front " << front << "   back " << back << '\n'; // 뒤에 \n을 넣으면 출력이 안되는데 왜 그럴까 -> windows에서만 문제가 생긴다
        // 윈도우에서는 \n을 출력한 이후에 다른 출력물들이 나오지 않는다
        // cout << "front " << front << "   back " << back << endl;

        if(error_flag) cout << "error" << endl;
        else {
            // cout << "front: " << front << "  back: " << back << endl;
            cout << '[';
            if(!is_rev) for(int i=front; i<back; i++) cout << list[i];
            else {
                int cnt = 0;
                for(int i=back-1; i>=front; i--) {
                    if(list[i] != '[' && list[i] != ',') {
                        cnt++;
                    } else {
                        for(int j=1; j<=cnt; j++) {
                            cout << list[i+j];
                        }
                        cout << list[i];
                        cnt = 0;
                    }
                }
                for(int j=0; j<cnt; j++) {
                    cout << list[front+j];
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}
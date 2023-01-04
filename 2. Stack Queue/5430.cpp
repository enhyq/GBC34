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
    // 01    67
    // [1,2,3]
    while(T--) {
        cin >> command;
        cout << "command entered!" << endl;
        cin >> size;
        cout << "size enterd!" << endl;
        cin >> list;
        cout << "list enterd!" << endl;

        int list_size = list.size();
        int front=1, back=list_size-1;
        bool is_rev = false, error_flag = false;

        cout << "list size is: " << list_size << endl;
        cout << "command length is: " << command.length() << endl;

        for(int i=0; i < command.length(); i++) {
            if(command[i] == 'D') {
                if(is_rev) back -= 2;
                else front += 2;
                if(front >= list_size || back <= 0 || front > back) {
                    // error case
                    error_flag = true;
                    break;
                }
            } else if (command[i] == 'R') is_rev = !is_rev;
            cout << "iter " << i << endl;
        }
        // cout << "front " << front << "   back " << back << '\n'; // 뒤에 \n을 넣으면 출력이 안되는데 왜 그럴까
        cout << "front " << front << "   back " << back << endl;

        if(error_flag) cout << "error" << endl;
        else {
            cout << '[';
            if(front+1 != back) {
                if(!is_rev) for(int i=max(front,1); i<back; i++) cout << list[i];
                else        for(int i=back-1; i>=max(front,1); i--) cout << list[i];
            }
            cout << "]" << endl;
        }
        cout << "hi" << endl;
    }

    return 0;
}
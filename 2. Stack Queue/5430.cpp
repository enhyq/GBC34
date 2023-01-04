#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// time limit is 1 seconds 
// there are 1 ~ 100,000 test cases
// 0 ~ 100,000 number of elements
// + need to parse the numbers 

//

vector<string> split(string input, char delimiter);

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;

    string command;
    int size;
    string list;
    while(T--) {
        cin >> command;
        cin >> size;

        int D_cnt = 0;

        cin >> list;
        list.erase(list.end()-1); // remove '[' and ']'
        list.erase(list.begin());
        vector<string> result = split(list, ',');
        
        bool is_reverse = false;
        vector<string>::iterator iter;
        vector<string>::reverse_iterator r_iter;

        bool error_flag = false;

        for(int i=0; i<command.length(); i++){
            if(command[i] == 'R') {
                is_reverse = !is_reverse;
            } else if (command[i] == 'D') {
                // error case
                if(result.size() == 0) {
                    error_flag = true;
                    break;
                }

                if(!is_reverse) iter = result.begin();
                else iter = result.end()-1;

                result.erase(iter);
            }
        }
        if(error_flag) cout << "error" << '\n';
        else {
            cout << '[';
            if(is_reverse){
                r_iter = result.rbegin();
                for( ; r_iter != result.rend(); r_iter++){
                    if(r_iter != result.rbegin()) cout << ',';
                    cout << *(r_iter);
                }
            } else {
                iter = result.begin();
                for( ; iter != result.end(); iter++){
                    if(iter != result.begin()) cout << ',';
                    cout << *(iter);
                }
            }
            cout << ']' << '\n';
        }
        
    }

    return 0;
}

// code from https://ssungkang.tistory.com/entry/C-string-%EB%AC%B8%EC%9E%90%EC%97%B4-%EB%82%98%EB%88%84%EB%8A%94-split
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> A(10);
//   int A[10];
  // vector<int> V;
  int n, n2, n3;
  cin >> n >> n2 >> n3;

  int mul = n * n2 * n3;
  string s = to_string(mul);
  for(int j=0;j<10;j++){
      for(int i=0;i<s.length();i++){
          string j1=to_string(j);
          s
          string j2=to_string(s[i]);

          cout << j2 << '\n';
          if(j1.compare(j2)==0){
              A[j]++;
          }
      }
  }
  cout << '\n';

  for(int i=0;i<10;i++){
      cout << A[i] << '\n';

  }
  cout<<'\n';
  return 0;
}
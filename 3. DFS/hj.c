#include <stdio.h>
#include <string.h>

int recount=1;
int recursion(const char *s, int l, int r){
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else{
      recount++;
      return recursion(s, l+1, r-1);
    }
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
  int count;
  char a[1001]={0, };
  scanf("%d", &count);
  
  for(int i=0;i<count;i++){
    scanf("%s", a);
    printf("%d ", isPalindrome(a));
    printf("%d\n", recount);
    // memset(a, 0, sizeof(char)*1001);
    recount=1;
  }
  return 0;
}
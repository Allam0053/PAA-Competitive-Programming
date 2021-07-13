#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
// template <typename T>

// T getNum(){
//     T res = 0;
//     char c;
//     while(1){
//         c=getchar_unlocked();
//         if(c==' ' || c=='\n')continue;
//         else break;
//     }
//     res=c-'0';
//     while(1){
//         c=getchar_unlocked();
//         if(c>='0'&&c<='9')res=10*res+c-'0';
//         else break;
//     }
//     return res;
// }

int countSameDiff(int *arr, int len) {
  int count = 0;
  for (int it1 = 0; it1 < len; it1++) {
    for (int it2 = 0; it2 < len; it2++) {
      if ((arr[it2] - arr[it1]) == (it2 - it1) && (it1 < it2)) count++;
    }
  }
  return count;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--){
    int len;
    scanf("%d", &len);
    int arr[len];
    for (int i = 0; i < len; i++) {
      scanf("%d", &arr[i]);
    }
    printf("%d\n", countSameDiff(arr, len));
  }
  return 0;
}
/*
4
6
3 5 1 4 6 6
3
1 2 3
4
1 3 3 4
6
1 6 3 4 5 6
*/
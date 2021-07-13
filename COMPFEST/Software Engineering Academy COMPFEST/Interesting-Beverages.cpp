#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
template <typename T>

T getNum(){
    T res = 0;
    char c;
    while(1){
        c=getchar_unlocked();
        if(c==' ' || c=='\n')continue;
        else break;
    }
    res=c-'0';
    while(1){
        c=getchar_unlocked();
        if(c>='0'&&c<='9')res=10*res+c-'0';
        else break;
    }
    return res;
}

int getmychance (int *price_in_shop, int val, int len) {

  if (val >= price_in_shop[len - 1]) return len;
  if (val < price_in_shop[0]) return 0;

  int l = 0, r = len - 1;
  int m = (l + r) / 2;
  while (l < r) {
    m = (l + r) / 2;
    if (price_in_shop[m] > val) {
      r = m;
    } else if (price_in_shop[m] < val) {
      l = m + 1;
    } else break;
  }
  while (m < len) {
    if (price_in_shop[m + 1] == val) m++;
    else break;
  }
  while (m >= 0) {
    if (price_in_shop[m] > val) m--;
    else break;
  }
  return m+1;
}

int main() {
    int n, days;

    // scanf("%d", &n);
    n = getNum<int>();
    int price_in_shop[n];
    for(int i = 0; i < n; i++) {
      // scanf("%d", (price_in_shop+i));
      price_in_shop[i] = getNum<int>();
    }

    // scanf("%d", &days);
    days = getNum<int>();
    int coins_in_day[n];
    for(int i = 0; i < days; i++) {
      // scanf("%d", (coins_in_day+i));
      coins_in_day[i] = getNum<int>();
    }

    sort(price_in_shop, price_in_shop+n);
    for (int i = 0; i < days; i++) {
      printf("%d\n", getmychance(price_in_shop, coins_in_day[i], n));
    }

    return 0;
}

/*
in:
5
3 10 8 6 11
4
1
10
3
11

out:
0
4
1
5

3 6 8 10 11
*/
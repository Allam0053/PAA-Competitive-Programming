#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T, B, D;
    scanf("%d", &T);
    while(T--) {
      scanf("%d %d", &B, &D);
      printf("%d\n", B/D + B%D);
    }
    return 0;
}

/* Enter
3
7 4
4 7
4000 7

4
4
574
*/
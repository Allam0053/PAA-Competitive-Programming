#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


int main() {
    int T, A, B, N, P;
    double ds;
    string s, jadi;
    scanf("%d", &T);
    while(T--) {
      scanf("%d %d %d %d", &A, &B, &N, &P);
      ds = (float)A / (float)B;
      ostringstream ss;
      ss << fixed << ds;
      s = ss.str();
      jadi = s.substr(2, N - 1 + 2);
      cout << jadi << endl;
    }
    return 0;
}
/* Enter
4
9 12 7 3
7 8 6 5
8 15 7 7
10 17 3 11

21
18
2
1
*/
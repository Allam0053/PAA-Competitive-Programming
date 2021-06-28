#include <stdio.h>
#include <algorithm>
using namespace std;

int main () {
  int pen, apple, lol = 100500, trash = 0;
  scanf("%d%d", &pen, &apple);
  while (apple != min(apple, trash)) { // while (apple > trash)
    while (pen == max(apple, pen)) { // while (pen)
      pen = abs(pen - apple);
    }
    int pineapple = pen;
    pen = apple;
    apple = pineapple;
  }
  printf("%d\n", pen + apple);
  return 0;
}

//================================================================
#include <iostream>
#include <algorithm>
using namespace std;
int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int pen, apple;
  cin >> pen >> apple;
  cout << __gcd(pen, apple) << endl;
  return 0;
}
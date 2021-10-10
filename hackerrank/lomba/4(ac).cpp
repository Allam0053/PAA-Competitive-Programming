#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
typedef unsigned long long ull;
using namespace std;

ull arr[] = {
  1,
  2,
  3,
  5,
  8,
  13,
  21,
  34,
  55,
  89,
  144,
  233,
  377,
  610,
  987,
  1597,
  2584,
  4181,
  6765,
  10946,
  17711,
  28657,
  46368,
  75025,
  121393,
  196418,
  317811,
  514229,
  832040,
  1346269,
  2178309,
  3524578,
  5702887,
  9227465,
  14930352,
  24157817,
  39088169,
  63245986,
  102334155,
  165580141,
  267914296,
  433494437,
  701408733,
  1134903170
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    int T;
    cin >> T;
    while (T--) {
      int n;
      cin >> n;
      char out[45];
      int basis[44] = {0};
      bool first = true;
      for (int i = 43; i >= 0; i--) {
        if (first) {
          if (arr[i] < n){
            n -= arr[i];
            basis[i] = 1;
            first = false;
          }
        }
        if (arr[i] <= n){
          n -= arr[i];
          basis[i] = 1;
        }
      }
      
      first = true;
      for (int i = 43; i >= 0; i--) {
        if (first) {
          if (basis[i] == 0) {
            continue;
          } else {
            first = false;
          }
        }
        char temp[45];
        sprintf(temp, "%d", basis[i]);
        cout << temp;
        // cout << basis[i];
      } cout << endl;
    }
    return 0;
}
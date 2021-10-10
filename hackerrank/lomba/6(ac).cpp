#include <iostream>
#include <algorithm>
using namespace std;
 
int findWater(int arr[], int n)
{
    int left[n];
    int right[n];
    int water = 0;
 
    left[0] = arr[0];
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], arr[i]);
    }
 
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], arr[i]);
    }

    for (int i = 0; i < n; i++) {
        water += min(left[i], right[i]) - arr[i];
    }
 
    return water;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
      int n, q;
      cin >> n >> q;
      int arr[n];
      for (int i = 0; i < n; i++) {
        cin >> arr[i];
      }

      while (q--) {
        char query;
        cin >> query;
        if (query == 'U') {
          int pos, h;
          cin >> pos >> h;
          arr[pos - 1] += h;
        } else if (query == 'P') {
          cout <<  findWater(arr, n) << endl;
        }
      }
    }
    
    return 0;
}
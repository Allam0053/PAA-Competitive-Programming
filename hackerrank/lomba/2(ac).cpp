#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x_barjo, y_barjo, T;
    double mintime = (double)999999999;
    cin >> x_barjo >> y_barjo;
    cin >> T;
    while (T--) {
      double x, y, v, dist_x, dist_y, dist;
      cin >> x >> y >> v;
      dist_x = abs(x_barjo - x);
      dist_y = abs(y_barjo - y);

      dist = sqrt( dist_x * dist_x + dist_y * dist_y );
      double time = dist / v;
      if (mintime > time) {
        mintime = time;
      }
    }
    cout << mintime << endl;
    return 0;
}

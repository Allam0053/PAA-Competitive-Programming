#include <bits/stdc++.h>
using namespace std;
 
int coinchange(vector<int>& a, int v, int n,
               vector<vector<int> >& dp)
{
    if (v == 0)
        return dp[n][v] = 1;
    if (n == 0)
        return 0;
    if (dp[n][v] != -1)
        return dp[n][v];
    if (a[n - 1] <= v) {
        return dp[n][v] = coinchange(a, v - a[n - 1], n, dp)
                          + coinchange(a, v, n - 1, dp);
    }
    else 
        return dp[n][v] = coinchange(a, v, n - 1, dp);
}
int main()
{
    int tc;
    while (cin >> tc) {
        int n;
        n = 5;
        vector<int> a = { 1, 5, 10, 25, 50 };
        vector<vector<int> > dp(n + 1,
                                vector<int>(tc + 1, -1));
        int res = coinchange(a, tc, n, dp);
        cout << res << endl;
    }
}

//  50 sen, 25 sen, 10 sen, 5 sen, dan 1 sen.
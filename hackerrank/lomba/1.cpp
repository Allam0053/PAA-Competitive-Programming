#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
 
ull count( int S[], int m, int n )
{
    int i, j, x, y;
 
    int table[n + 1][m];
     
    for (i = 0; i < m; i++)
        table[0][i] = 1;
 
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;
 
            y = (j >= 1) ? table[i][j - 1] : 0;
 
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}
 
// Driver Code
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int arr[] = {1, 5, 10, 25, 50 };
    int m = 5;
    int n;
    while (cin >> n) {
      cout << count(arr, m, n) << endl;
    }
    return 0;
}
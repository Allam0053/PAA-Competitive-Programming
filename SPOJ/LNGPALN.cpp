#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

bool valid (string s) {
    for (int i=0; i < s.length()-1; i++) {
        if (s[i] == s[i+1]) return 0;
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s, ans="";
        cin >> s;
        int n = s.length();
        bool dp[n+5][n+5];
        memset(dp, 0, sizeof(dp));
        for(int i=n; i >= 1; i--) {
            for (int j=1; j <= n; j++) {
                if (i > j) continue;
                if (i == j) dp[i][j] = true;
                else if (j == i+1) {
                    if (s[i-1] == s[j-1])
                        dp[i][j] = true;
                } else {
                    if (s[i-1] == s[j-1])
                        dp[i][j] = dp[i+1][j-1];
                }
            }
        }
        int lo = 1, hi = (n+1)/2;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            int k = 2*mid-1;
            string temp="";
            for (int i=k; i <= n; i++) {
                string now = s.substr(i-k, k);
                if (dp[i-k+1][i] && valid(now)) {
                    if (temp == "") {
                        temp = now;
                    } else if (now < temp) temp = now;
                }
            }
            if (temp == "") {
                hi = mid - 1;
            } else {
                ans = temp;
                lo = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// valid (s)
//     for i to s.length()-1
//         if s[i]==s[i+1] 
//             return 0
//     return 1

// input (t)
// while t>0
//     input (s)
//     n = s.length()
//     for i=n downto 1
//         for j=1 to n
//             if i>j
//                 continue
//             if i==j
//                 dp[i][j] = true
//             else if j==i+1
//                 if s[i-1]==s[j-1]
//                     dp[i][j] = true
//             else
//                 if s[i-1]==s[j-1]
//                     dp[i][j]=dp[i+1][j-1]
//     lo=1
//     hi=(n+1)/2
//     while lo<=hi
//         mid = (lo+hi)/2
//         k = 2*mid - 1
//         temp = ""
//         for i=k to n
//             now = s.substr(i-k,k)
//             if dp[i-k+1][i] && valid(now)
//                 if temp=""
//                     temp = now
//                 else if now<temp
//                     temp = now
//         if temp=""
//             hi=mid-1
//         else
//             ans = temp
//             lo = mid + 1
//     print ans
//     t = t - 1


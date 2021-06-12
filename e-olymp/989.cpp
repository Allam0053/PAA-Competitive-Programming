#include <cstdio>
using namespace std;
int n, dp[101];

int main () {
    int n;
    scanf("%d", &n);
    dp[0]=1;
    for (int i = 1; i<=n; i++) {
        for (int j=n; j>=0; j--) {
            if (dp[j] && i+j<101)dp[j+i] += dp[j];
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}

// declare:
//     n: long long
//     dp[101]: long long

// main ()
//     read n
//     dp[0] = 1
//     for i=1 to n
//         for j=n downto 0
//             if dp[j] > 0 && i+j<101
//                 dp[j+i] = dp[j+i] + dp[j]
        
//     write dp[n]

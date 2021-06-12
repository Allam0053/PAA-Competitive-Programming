#include <cstdio>
using namespace std;
#define MOD 1000000007
typedef long long ll;
ll n,k, dp[1000001];

int main () {
    scanf("%lld %lld", &n, &k);
    dp[0] = 1;
    for (ll a = 1; a <= n; a++) {
        if(a-k < 0) { //zona kuning
            dp[a] = (2*dp[a-1]%MOD);
        } else if (a == k) { //zona ungu
            dp[a] = (2*dp[a-1]%MOD)-1;
        } else { //zona peach
            dp[a] = (2*dp[a-1]%MOD)-dp[a-k-1];
        }
        if (dp[a] < 0) dp[a] = dp[a]+MOD;
    }
    printf("%lld\n", dp[n]);
    return 0;
}

// declare:
//     n,k, dp[1000001]: long long
//     MOD = 1000000007: long long

// main ()
//     read n k
//     dp[0] = 1
//     for a=1 to n
//         if a-k < 0 //zona kuning
//             dp[a] = (2*dp[a-1] mod MOD)
//         else a == k //zona ungu
//             dp[a] = (2*dp[a-1] mod MOD)-1
//         else //zona peach
//             dp[a] = (2*dp[a-1] mod MOD)-dp[a-k-1]
        
//         if (dp[a] < 0)
//             dp[a] = dp[a] + MOD
    
//     write dp[n]
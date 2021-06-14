#include <stdio.h>
#define MOD 1000000007
template <typename T>
T getNum(){
    T res = 0;
    char c;
    while(1){
        c=getchar_unlocked();
        if(c==' ' || c=='\n')continue;
        else break;
    }
    res=c-'0';
    while(1){
        c=getchar_unlocked();
        if(c>='0'&&c<='9')res=10*res+c-'0';
        else break;
    }
    return res;
}

int dp[101][10001];
int main () {
    int pow[100001];
    pow[0] = 1;
    pow[1] = 2 % MOD;
    for (int i = 2; i <= 100000; i++) {
        pow[i] = (pow[i - 1] * 2) % MOD;
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 10000; j++) {
            if (i > j) {
                dp[i][j] = 0;
                continue;
            } else if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            int temp = pow[j - (i + 1)] - dp[i][j - (i + 1)];
            if (temp < 0) temp += MOD;
            dp[i][j] = ((2 * dp[i][j-1]) % MOD + temp) % MOD;
        }
    }
    int T,N,K;
    T = getNum<int>();
    while (T--) {
        N = getNum<int>();
        K = getNum<int>();
        int temp = pow[N - 1] - dp[K][N - 1];
        if (temp < 0) temp += MOD;
        printf("%d\n", temp);
    }
}
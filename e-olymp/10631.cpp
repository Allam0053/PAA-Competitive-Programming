#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int length[10002] = {};
// vector <int> length;
int dp[2] = {};

int main(){
    int costPerCut = 0;
    int salePrice = 0;
    int n = 0;
    int i = 0;
    int temp;
    int maxLength = INT_MIN;

    scanf("%d %d %d", &costPerCut, &salePrice, &n);

    for (i = 0; i < n;i++){
        scanf("%d", &length[i]);
        // length.push_back(temp);
        maxLength = max(length[i], maxLength);
    }
    int income, uniform, cuts;

    for (int len=1; len<=maxLength; len++) {
        income = 0;
        uniform = 0;
        cuts = 0;
        
        for (i =0; i<n;i++){
            uniform += length[i] / len;

            if (length[i] % len == 0){
                cuts += length[i] / len - 1;
            } else {
                cuts += length[i] / len;
            }
        }

        income = salePrice * len * uniform - (cuts * costPerCut);

        dp[len % 2] = max(income, dp[len % 2]);
    }

    printf("%d\n", max(dp[0], dp[1]));

    getchar();
    getchar();
}
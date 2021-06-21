#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD=3367900313;
ll dp[2505];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  dp[1]=1; dp[2]=9801;
  for(ll i=3; i<=2500; i++) {
    dp[i] = (9602 * dp[i-1]) % MOD;
    dp[i] = (dp[i] - dp[i - 2] + MOD) % MOD;
    dp[i] = (dp[i] + 200) % MOD;
  }
  ll t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << dp[n] << '\n';
  }
  return 0;
}
/*
pada problem ini, diminta untuk mencetak bilangan yang merupakan sequence dari bilangan square dan pentagon.
dimana bilangan square adalah n*n sedangkan pentagon adalah  (3*n*n - n) / 2.
akan diberikan bilangan integer yang merupakan nomor urut dari bilangan tersebut lalu program harus memberikan keluaran seperti yang telah dijelaskan.
contoh:
input:
1
output:
1

input:
2
output:
9801

bilangan pada output bisa saja sangat besar, maka dari itu sangat tidak efisien bila dilakukan loop untuk mencari bilangan secara linier dengan memeriksa apakah bilangan tersebut valid.

dengan menggunakan referensi dari OEIS, didapat formula untuk problem ini.
a(n) = 9602*a(n-1) - a(n-2) + 200
dengan n adalah nomor urut dari bilangan yang valid.
*/

/*
MOD=3367900313
dp[2505]
main ()
    dp[1]=1
    dp[2]=9801
    for i=3 to 2500
        dp[i] = (9602 * dp[i-1]) mod MOD
        dp[i] = (dp[i] - dp[i - 2] + MOD) mod MOD
        dp[i] = (dp[i] + 200) mod MOD
    input (t)
    while t>0
        input (n)
        print dp[n]
        print '\n'
        t = t - 1
*/
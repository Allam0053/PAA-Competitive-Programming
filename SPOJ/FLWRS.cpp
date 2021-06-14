#include <iostream>
using namespace std;
typedef long long ll;

ll orders[2020];
ll n, m;

int main () {
    ll t1, t2, t3, t4;
    int i, hasil;
    cin >> n >> m;
    orders[0] = 1; orders[1] = 1; orders[2] = 0; orders[3] = 0;
    if (n > 3) {
        for (i = 4; i <= n; i++) {
            t1 = ((i+1)%m * orders[i-1])%m;
            t2 = ((i-2)%m * orders[i-2])%m;
            t3 = ((i-5)%m * orders[i-3])%m;
            t4 = ((i-3)%m * orders[i-4])%m;
            orders[i] = (t1 - t2 - t3 + t4) % m;
        }
    }
    hasil = (int) orders[n] % m;
    while (hasil < 0) hasil += m;
    printf("%d\n", hasil);
    return 0;
}
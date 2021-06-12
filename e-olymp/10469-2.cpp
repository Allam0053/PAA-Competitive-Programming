#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

// template <typename T>
// T getNum() {
//     T res = 0;
//     char c;
//     while(1){
//         c=getchar_unlocked();
//         if(c==' ' || c=='\n')continue;
//         else break;
//     }
//     res=c-'0';
//     while(1){
//         c=getchar_unlocked();
//         if(c>='0'&&c<='9')res=10*res+c-'0';
//         else break;
//     }
//     return res;
// }

int main () {
    ll n, k, maxnk;
    scanf("%lld %lld", &n, &k);
    // n = getNum<ll>();
    // k = getNum<ll>();
    maxnk = max(n, k);
    ll r[n];
    ll c[n];
    ll maxr=0, mxc=0;
    for (ll i = 0; i<n; i++) {
        scanf("%lld", &r[i]);
        // r[i] = getNum<ll>();
        maxr = max(maxr, r[i]);
    }
    for (ll i = 0; i<n; i++) {
        scanf("%lld", &c[i]);
        // c[i] = getNum<ll>();
    }

    ll left = 0;
    ll right = maxr;
    ll mid = (right + left) / 2;
    ll res, eMax;

    ll equationLeft = 0, equationMid = 0, equationRight = 0;
    ll eLeft, eMid, eRight, eMaxLeft=0, eMaxMid=0, eMaxRight=0;

    while (left < right) {
        mid = (right + left) / 2;
        equationLeft = equationMid = equationRight = 0;
        eLeft = eMid = eRight = eMaxLeft = eMaxMid = eMaxRight = 0;
        /* look for the minimum 
         * if mid-1 is lesser than mid then bst goes to the left, 
         * if mid+1 is lesser than mid then bst goes to the right
        */
        for (ll i = 0; i<n; i++) {
            eLeft = max((ll)0, min(r[i], mid-1));
            eMid = min(r[i], mid);
            eRight = min(right, min(r[i], mid+1));
            equationLeft += (abs(r[i] - eLeft) * c[i]);
            equationMid += (abs(r[i] - eMid) * c[i]);
            equationRight += (abs(r[i] - eRight) * c[i]);
        }
        eMaxLeft = max(mid-1, (ll)0 );
        eMaxRight = min(mid+1, right);// ganti mid
        equationLeft += (eMaxLeft*k);
        equationMid += (mid*k);
        equationRight += (eMaxRight*k);

        if (equationLeft < equationMid) {
            res = equationLeft;
            right = mid - 1;
        } else if (equationRight < equationMid) {
            res = equationRight;
            left = mid + 1;
        } else {
            res = equationMid;
            break;
        }
    }

    printf("%lld\n", res);
    return 0;
}

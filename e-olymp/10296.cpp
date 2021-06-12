#include <stdio.h>
#include <map>
using namespace std;
typedef long long ll;
map<ll,ll> savedCalculation;

ll f_x_ (ll x) {
    if (savedCalculation.count(x))
        return savedCalculation[x];

    ll xval = f_x_(x/2) + f_x_(x/3);
    savedCalculation[x] = xval;
    return xval;
}

int main () {
    savedCalculation[0] = 1;
    ll x;
    scanf("%lld", &x);
    printf("%lld\n", f_x_(x));
    return 0;
}

// declare:
//     <map> mp: long long
//     u: long long

// rec(u: long long): long long
//     if mp.count(u) 
//         return mp[u]
//     nval: long long
//     nval = rec(u/2) + rec(u/3);
//     mp[u] = nval;
//     return nval;

// mp[0]=1
// read u
// write rec(u)
// return

#include <stdio.h>
using namespace std;
typedef unsigned long long ll;
const ll MOD = 314159;

ll modexp(ll b, ll e, ll m) {
    ll r = 1;
    while (e>0) {
        if ((e & 1) == 1) {
            r = (r*b)%m;
        }
        e >>= 1;
        b = (b*b) % m;
    }
    return r;
}

ll inv2;

int main () {
    ll T, N, hasil;
    inv2=modexp(2,MOD-2,MOD);
    scanf("%lld", &T);
    for(int i=0; i<T; i++) {
        scanf("%lld", &N);
        hasil=((modexp(8,N,MOD)+modexp(10,N,MOD))*inv2)%MOD;
        printf("%lld\n", hasil);
    }
    return 0;
}

// function modexp (b, e, m: long long) : long long
//     declare r: long long
//     r=1
//     while e>0
//         if e&1 == 1
//             r=(r*b)%m
//         e=e>>1;
//         b=(b*b)%m
//     return r

// declare
//     inv2, MOD: long long
//     T, N, hasil: long long

// MOD=314159

// inv2=modexp(2,MOD-2,MOD)
// read T
// while T>0
//     read N
//     hasil=( (modexp(8,N,MOD)+modexp(10,N,MOD)) * inv2 )%MOD
//     write hasil

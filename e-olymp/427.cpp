#include <stdio.h>
using namespace std;
typedef long long LL;

LL modex(LL b, LL e, LL m){
    LL r=1;
    while(e>0){
        if((e&1)==1){
            r=(r*b)%m;
        }
        e>>=1;
        b=(b*b)%m;
    }
    return (LL)r;
}

int main () {
    LL t;
    scanf("%lld", &t);
    while(t--){
        LL n,m;
        scanf("%lld%lld", &n,&m);
        LL ans1=modex(2LL, n,m);
        LL ans2=((n%m)*((n-4LL)%m))%m+6LL;
        LL res= ((ans1*ans2)%m-6LL)%m;
        if(res<0)res+=m;
        printf("%lld\n", res);
    }
    return 0;
}

// declare:
//     t,n,m,ans1,ans2,res : long long

// function modexp (b, e, m: long long) : long long
//     declare r: long long
//     r=1
//     while e>0
//         if e&1 == 1
//             r=(r*b)%m
//         e=e>>1;
//         b=(b*b)%m
//     return r

// read t
// while t>0
//     read n
//     read m
//     ans1=modex(2, n,m)
//     ans2=((n%m)*((n-4)%m))%m+6
//     res= ((ans1*ans2)%m-6)%m
//     if(res<0)
//         res=res+m
//     write res

// return
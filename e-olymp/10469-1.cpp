#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

template <typename T>
T getNum() {
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

int main () {
    ll n, k, maxnk;
    // scanf("%lld %lld", &n, &k);
    n = getNum<ll>();
    k = getNum<ll>();
    maxnk = max(n, k);
    ll r[n];
    ll c[n];
    ll maxr=0, mxc=0;
    for (ll i = 0; i<n; i++) {
        // scanf("%lld", &r[i]);
        r[i] = getNum<ll>();
        maxr = max(maxr, r[i]);
    }
    for (ll i = 0; i<n; i++) {
        // scanf("%lld", &c[i]);
        c[i] = getNum<ll>();
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
            if (mid-1<0) eLeft = 0;
            else eLeft = min(r[i], mid-1);
            eMid = min(r[i], mid);
            if (mid+1>right) eRight = right;
            else eRight = min(r[i], mid+1);
            equationLeft += (abs(r[i] - eLeft) * c[i]);
            equationMid += (abs(r[i] - eMid) * c[i]);
            equationRight += (abs(r[i] - eRight) * c[i]);
            eMaxLeft = max(eMaxLeft, eLeft);
            eMaxMid = max(eMaxMid, eMid);
            eMaxRight = max(eMaxRight, eRight);// ganti mid
        }
        equationLeft += (eMaxLeft*k);
        equationMid += (eMaxMid*k);
        equationRight += (eMaxRight*k);

        if (equationLeft < equationMid) {
            eMax = eLeft;
            res = equationLeft;
            right = mid - 1;
        } else if (equationRight < equationMid) {
            eMax = eRight;
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

// main ()
//     declare:
//         n, k, maxnk: long long
//     read n k
//     maxnk = max(n, k)
//     declare:
//         r[n], c[n]: long long
//         maxr, mxc: long long
    
//     for i=0 to n-1
//         read r[i]
//         maxr = max(maxr, r[i])
//     for i=0 to n-1
//         read c[i]

//     declare:
//         left, mid, right, res, eMax: long long
//     left = 0
//     right = maxr
//     mid = (right + left) / 2

//     declare:
//         equationLeft, equationMid, equationRight: long long
//         eLeft, eMid, eRight, eMaxLeft, eMaxMid, eMaxRight: long long

//     while (left < right) {
//         mid = (right + left) / 2
//         equationLeft = 0
//         equationMid = 0
//         equationRight = 0
//         eLeft = 0
//         eMid = 0
//         eRight = 0
//         eMaxLeft = 0
//         eMaxMid = 0
//         eMaxRight = 0
//         /* look for the minimum 
//          * if mid-1 is lesser than mid then bst goes to the left, 
//          * if mid+1 is lesser than mid then bst goes to the right
//         */
//         for i=0 to n-1
//             if mid-1<0 
//                 eLeft = 0
//             else 
//                 eLeft = min(r[i], mid-1)
//             eMid = min(r[i], mid)
//             if mid+1>right
//                 eRight = right
//             else 
//                 eRight = min(r[i], mid+1)
//             equationLeft = equationLeft + (abs(r[i] - eLeft) * c[i])
//             equationMid = equationMid + (abs(r[i] - eMid) * c[i])
//             equationRight = equationRight + (abs(r[i] - eRight) * c[i])
//             eMaxLeft = max(eMaxLeft, eLeft)
//             eMaxMid = max(eMaxMid, eMid)
//             eMaxRight = max(eMaxRight, eRight)
//         equationLeft = equationLeft + (eMaxLeft*k)
//         equationMid = equationMid + (eMaxMid*k)
//         equationRight = equationRight + (eMaxRight*k)

//         if equationLeft < equationMid 
//             eMax = eLeft
//             res = equationLeft
//             right = mid - 1
//         else equationRight < equationMid
//             eMax = eRight
//             res = equationRight
//             left = mid + 1
//         else
//             res = equationMid
//             break
        
//     }

//     write res

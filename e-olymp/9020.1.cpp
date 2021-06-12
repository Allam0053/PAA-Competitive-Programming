#include <stdio.h>
#include <stdbool.h>
typedef long long ll;
bool cek (ll mid, ll *arr, ll n, ll K) {
    ll count = 0;
    ll sum = 0;
    for (ll i=0; i<n; i++) {
        if (arr[i] > mid) return false;
        sum += arr[i];
        if (sum > mid) {
            count++;
            sum = arr[i];
        }
    }
    count++;
    if (count <= K) return true;
    return false;
}
int main () {
    ll n, K, bot=0, mid, top=0, ans=0;
    scanf("%lld %lld", &n, &K);
    ll arr[n];
    for (ll i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
        if (bot < arr[i]) bot = arr[i];
        top += arr[i];
    }
    while (bot <= top) {
        mid = (bot+top)/2;
        if (cek(mid, arr, n, K)) {
            ans = mid;
            top = mid-1;
        } else {
            bot = mid+1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

// declare:
//     n, K, bot, mid, top, ans, arr[0..n-1]: long long


// function cek(long long mid, long long arr[0..n-1], long long n, long long K) : bool
//     count = 0 : long long
//     sum = 0 : long long
//     for i=0 to n-1
//         if arr[i]>mid 
//             return false
//         sum += arr[i]
//         if sum>mid 
//             count=count+1
//             sum = arr[i]
//     count=count+1
//     if count<=K
//         return true
//     return false

// bot=0
// top=0
// read n, K
// for i=0 to n-1
//     read arr[i]
//     if bot<arr[i]
//         bot=arr[i]
//     top=top+arr[i]
// while bot<=top
//     mid=(bot+top)/2
//     if (cek(mid, arr, n, K))
//         ans=mid
//         top=mid-1
//     else
//         bot=mid+1
// write ans
// return

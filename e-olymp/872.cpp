#include <stdio.h>
#include <algorithm>
using namespace std;

int n, k;
long long sum,MX,atas,bawah,mid, data[10010];

long long calc (long long u) {
    long long temp = 0;
    for (int i=0; i<n; i++) temp += (data[i]/u);
    return temp;
}

int main () {
    scanf("%d %d", &n, &k);
    sum = 0;
    MX = 0;
    for (int i=0; i<n; i++) {
        scanf("%lld", &data[i]);
        if (MX<data[i]) MX = data[i];
        sum+=data[i];
    }
    if (sum<k) printf("0");
    else {
        atas = min(MX+1, sum/k+1);
        bawah = 1;
        while (atas-1>bawah) {
            mid = (atas+bawah)/2;
            printf("\natas: %lld\nmid: %lld\nbawah: %lld\n", atas, mid, bawah);
            if (calc(mid)<k) atas = mid;
            else bawah = mid;
        }
        printf("%lld", bawah);
    }
    printf("\n");
    return 0;
}

/*
analisis singkat:
  - jika total panjang segment input lebih kecil dari K, maka 0
  - jika total panjang segment input sama dengan K, maka panjang 1
  - jika total panjang segment input lebih besak dari K maka untuk mencari panjang
    segment baru terpanjang sehinggak mendapatkan k segment baru yang sama panjang,
    dapat dilakukan binser panjang segment. dimana batas atasnya adalah total panjang
    semya segment awal dibagi k (atau jika panjang amksimal suatu segment input ada 
    yang lebih kecil, maka nilai tersebut menjadi batas atasnya) dan batas bawah 1
*/

// declare:
//     sum,MX,atas,bawah,mid, data[10010]: long int
//     n, k: int

// read n k
// for i=0 to n
//     read data[i]
//     if MX<data[i]
//         MX=data[i]
//     sum=sum+data[i]
// if sum<k
//     write "0"
// else sum=k
//     write "1"
// else
//     atas=min(MX+1, sum/k+1) //min return minimum value of given inputs
//     bawah=1
//     while atas-1>bawah      //binary search. search the max value of long of the segments that segments count equal to
//         mid=(atas+bawah)/2
//         if calc(mid)<k 
//             atas=mid
//         else
//             bawah=mid
//     write bawah
// return

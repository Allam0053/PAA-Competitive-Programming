#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[40];
int main(){
    a[1]=a[2]=1;
    for(int i=3; i<40; i++)a[i]=a[i-1]+a[i-2];
    int n;
    while(scanf("%d", &n)!=EOF){
        if(n==1)puts("1");
        else if(n==2)puts("2");
        else{
            int ans =0;
            for (int i=1; i<40; i++){
                if(n>=a[i]){
                    ans++;
                    n-=a[i];
                }else i=40;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

// deklarasi
//     ans, n, a[0..39]:integer

// a[1]=1
// a[2]=1
// for i=3 to 40
//     a[i]=a[i-1]+a[i-2]
// while read n
//     if n==1
//         write "1"
//     else n==2
//         write "2"
//     else 
//         ans=0
//         for i=1 to 40
//             if n>=a[i]
//                 ans=ans+1
//                 n=n-a[i]
//             else
//                 i=40
//         write ans
// return

#include <stdio.h>
#define uul unsigned long long

uul count(int val){
    if(val<0)return 0;
    return (val+3)*(val+2)*(val+1);
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int a,b,c,n;
        scanf("%d%d%d%d", &n,&a,&b,&c);
        uul ans = count(n) - count(n-a-1) - count(n-b-1) - count(n-c-1)
                    + count(n-a-b-2) + count(n-a-c-2) + count(n-b-c-2)
                    - count(n-a-b-c-3);
        printf("%llu", ans);
    }
}

// function count(val)
//     if val<0
//         return 0
//     return (val+3)(val+2)(val+1)/6

// declare:
//     t:int

// read(t)
// while t>0
//     n,a,b,c:integer
//     read(n,a,b,c)   
//     //calculate the total of the combination with function count
//     ans = count(n) – count(n-a-1) -count(n-b-1) – 
//         count(n-c-1) + count(n-a-b-2) +
//         count(n-b-c-2) + count(n-a-c-2) –
//         count(n-a-b-c-3)

//     write(ans)

// t=t-1


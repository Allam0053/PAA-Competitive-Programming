
#include <stdio.h>
#define uul unsigned long long
uul a[100000001];
uul list[1000001];
void PRINT (uul* A, uul* B){
    for(uul i=(*A); i<=(*B); i++){
        for(uul j=2*i; j<=(*B); j+=i)
            a[j]+=i;
    }
}
int main (){
    int T, N;
    uul A,B;
    
    scanf("%d", &T);
    while(T--){
        scanf("%llu %llu", &A, &B);
        PRINT(&A,&B);
    }
    return 0;
}
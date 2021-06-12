#include <stdio.h>

int main (){
    int t,n,k;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        if(k==1){
            for(int i=1;i<=n;i++)printf("1");
            printf(" ");
            for(int i=1;i<=n;i++)printf("9");
            printf("\n");
            continue;
        }
        printf("1");
        for(int i=1;i<=n-k+1;i++)printf("0");
        for(int i=1;i<=k-2;i++)printf("%d",i+1);
        printf(" ");
        for(int i=1;i<=n-k+1;i++)printf("9");
        for(int i=1;i<=k-1;i++)printf("%d", 9-i);
        printf("\n");
    }
    return 0;
}
#include <cmath>
#include <cstdio>

int main(){
    int T,k,n,r,m;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &k);
        n=(int)ceil((-1.0+sqrt(1.0+8.0*(double)k))/2.0);
        r=n*(n+1)/2;
        m=n+k-(r+1);
        printf("%d %d\n",m,n);
    }
    return 0;
}
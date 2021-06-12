#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int n,k,p,x;
    scanf("%d%d", &n, &k);
    while(k--){
        scanf("%d%d", &p, &x);
        if(p&1) n/=__gcd(n,x);
        printf("%d\n", n);
    }
    return 0;
}
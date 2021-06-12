#include <stdio.h>
#include <math.h>

int main () {
    long long in, testcase, bagi2, bagi4;
    scanf("%lld", &testcase);
    while(testcase--){
        scanf("%lld", &in);
        bagi2 = sqrt(in/2);
        bagi4 = sqrt(in/4);
        if (in==2 || in==4) 
            printf("YES\n");
        else if (in == bagi2*bagi2*2)
            printf("YES\n");
        else if (in == bagi4*bagi4*4)
            printf("YES\n");
        else 
            printf("NO\n");
    }
    return 0;
}
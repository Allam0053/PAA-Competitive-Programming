#include <stdio.h>
#include <math.h>

int main(){
    long long N, CaseNo=1, found,m,n,p,det,res,res1,det2,b;
    while(true){
        scanf("%lld",&N);
        if(N==(-1))break;

        printf("Case %lld:\n",CaseNo++);
        if (N == 1){
            printf("0 0 0\n"); continue;
        }
        if ((N == 0) || (N % 2)==1){
            printf("Impossible.\n");continue;
        }
        found = 0;
        for(m = 0; m < 100; m++) // m = Ellipses
        {
            res = 2 + 2 * m * (m - 1);
            if (res > N) break;
            for(p = 99; p >= 0; p--) // p = Triangles
            {
                res1 = res+ 3*p*(p-1) + (6*m*p);

                if (res1 > N) continue;
                b = (4*m) + (6*p) - 1;

                det2 = (b*b) - 4*(res1 - N);

                if (det2 >= 0){
                    det = (long long)sqrt(1.0 * det2);
                    if ((det * det == det2) && ((-b + det) % 2 == 0)){
                        n = (-b + det) / 2; // n = Circles
                        if ((n >= 0) && (n < 20000)){
                            printf("%lld %lld %lld\n",m,n,p);
                            found = 1;
                        }
                    }
                }
            }
        }
        if (!found) printf("Impossible.\n");

    }
    return 0;
}
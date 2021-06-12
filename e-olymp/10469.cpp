#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int lnit;

lnit rrr[1000100] = {};
lnit ccc[1000100] = {};

lnit calc(lnit r, lnit c, lnit e){
    return abs(r - e) * c;
}

lnit calcv(lnit r, lnit c, lnit e, lnit k, lnit mxe){
    lnit val = abs(r - e) * c + max(e, mxe) * k;
    return val;
}

lnit batch_equation(lnit *rrr, lnit *ccc, lnit n, lnit k, lnit mxe){
    lnit val = 0;
    for (lnit i = 0;i < n;i++){
        lnit e = min(rrr[i], mxe);
        val += calc(rrr[i], ccc[i], e);
    }
    
    val += mxe * k;

    return val;
}

int main(){
    lnit n = 0;
    lnit k = 0;
    lnit mxe = 0; //max of e
    lnit mxr = 0; //max of r

    scanf("%lld %lld", &n, &k);

    for (lnit i = 0;i < n;i++){
        scanf("%lld", &rrr[i]);
        if (rrr[i] > mxr) mxr = rrr[i];
    }
    for (lnit i = 0;i < n;i++){
        scanf("%lld", &ccc[i]);
    }

    lnit eqmxonly = mxr * k;

    lnit mxleft = 0;
    lnit mxright = mxr;
    lnit mxmid = (mxleft + mxright) / 2;

    while (mxleft <= mxright){
        mxmid = (mxleft + mxright) / 2;

        lnit mxeq = batch_equation(rrr, ccc, n, k, mxmid);
        lnit mxeqleft = batch_equation(rrr, ccc, n, k, (mxmid - 1 < 0) ? 0 : mxmid - 1);
        lnit mxeqright = batch_equation(rrr, ccc, n, k, (mxmid + 1 > mxr) ? mxr : mxmid + 1);

        if (mxeqleft < mxeq){
            mxright = mxmid - 1;
        } else if (mxeqright < mxeq){
            mxleft = mxmid + 1;
        } else {
            //impossible
            break;
        }
    }

    lnit valeq = batch_equation(rrr, ccc, n, k, mxmid);
    lnit valeqleft = batch_equation(rrr, ccc, n, k, (mxmid - 1 < 0) ? 0 : mxmid - 1);
    lnit valeqright = batch_equation(rrr, ccc, n, k, (mxmid + 1 > mxr) ? mxr : mxmid + 1);

    printf("%lld\n", min(valeq, min(valeqleft, valeqright)));

    getchar();
    getchar();
}
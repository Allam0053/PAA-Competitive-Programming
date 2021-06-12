    #include <stdio.h>
    #include <vector>
    #include <algorithm>
    #include <stdbool.h>
    using namespace std;
    #define ll int

    int main () {
        ll costPerCut, salePrice, n, tempHi, tempLo, totalProfit = 0, temp, totalUniformRods, minLength, totalCuts;
        vector<ll> length;
        scanf("%d %d %d", &costPerCut, &salePrice, &n);
        for (ll i=0; i<n; i++) {
            scanf("%d", &temp);
            length.push_back(temp);
            if(i>0) {
                minLength = min(temp, minLength);
            } else minLength = temp;
        }
        // totalProfit = salePrice * saleLength * totalUniformRods - totalCuts * costPerCut;
        int lo = 1;
        int hi = minLength;
        int mid;
        vector<ll> uniform(n, 0);
        vector<ll> cuts(n, 0);
        vector<ll> sisa(n, 0);
        // while (lo < hi) {
        //     mid = (hi+lo)/2;
        //     totalUniformRods = 0;
        //     totalCuts = 0;
        //     for(ll i=0; i<n; i++) {
        //         uniform[i] = length[i] / lo;
        //         sisa[i] = ((length[i] % lo));
        //         if (sisa[i] > 0) cuts[i] = uniform[i];
        //         else cuts[i] = uniform[i] - 1;
        //         totalUniformRods += uniform[i];
        //         totalCuts += cuts[i];
        //     }
        //     tempHi = (salePrice * hi * totalUniformRods) - (totalCuts * costPerCut);
        //     // printf("total cuts: %d\n", totalCuts);

        //     totalUniformRods = 0;
        //     totalCuts = 0;
        //     for(ll i=0; i<n; i++) {
        //         uniform[i] = length[i] / lo;
        //         sisa[i] = ((length[i] % lo));
        //         if (sisa[i] > 0) cuts[i] = uniform[i];
        //         else cuts[i] = uniform[i] - 1;
        //         totalUniformRods += uniform[i];
        //         totalCuts += cuts[i];
        //     }
        //     tempLo = (salePrice * lo * totalUniformRods) - (totalCuts * costPerCut);

        //     // printf("%d:%d <> %d:%d\n", hi, tempHi, tempLo, lo);
        //     // printf("total cuts: %d\n", totalCuts);

        //     if (tempHi > tempLo) {
        //         totalProfit = tempHi;
        //         lo = mid+1;
        //     } else if (tempHi < tempLo) {
        //         totalProfit = tempLo;
        //         hi = mid;
        //     } else {
        //         break;
        //     }
        //     // printf("\n");
        // }
        for (int j=1; j<minLength; j++) {
            totalUniformRods = 0;
            totalCuts = 0;
            for(ll i=0; i<n; i++) {
                uniform[i] = length[i] / j;
                sisa[i] = ((length[i] % j));
                if (sisa[i] > 0) cuts[i] = uniform[i];
                else cuts[i] = uniform[i] - 1;
                totalUniformRods += uniform[i];
                totalCuts += cuts[i];
            }
            tempHi = (salePrice * j * totalUniformRods) - (totalCuts * costPerCut);
            if(totalProfit < tempHi) totalProfit = tempHi;
        }

        printf("%d\n", totalProfit);

        return 0;
    }
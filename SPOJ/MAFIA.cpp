#include <cstdio>
#include <algorithm>
using namespace std;

int main () {
    int n,i,ans,buff;
    pair<int, int> interval[22];
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d%d", &interval[i].second, &interval[i].first);
    }
    sort(interval, interval+n);
    ans=1; buff=interval[0].first;
    for(i=1; i<n; i++) {
        if(interval[i].second > buff) {
            ans++;
            buff = interval[i].first;
        }
    }
    printf("%d\n", ans);
    return 0;
}
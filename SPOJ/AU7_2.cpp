#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAXN 100002
template <typename T>
T getNum(){
    T res = 0;
    char c;
    while(1){
        c=getchar_unlocked();
        if(c==' ' || c=='\n')continue;
        else break;
    }
    res=c-'0';
    while(1){
        c=getchar_unlocked();
        if(c>='0'&&c<='9')res=10*res+c-'0';
        else break;
    }
    return res;
}
int n, m;
int t[MAXN];
bool enough (ll time) {
    ll cnt = 0;
    for (int i=0; i<n; ++i) {
        ll here = time / t[i];
        if (here >= m || here + cnt >= m)
            return true;
        cnt += here;
    }
    return cnt >= m;
}

int main () {
    int T;
    // scanf("%d", &T);
    T = getNum<int>();
    while (T--) {
        // scanf("%d%d", &n, &m);
        n = getNum<int>();
        m = getNum<int>();
        int minTime = 1000000000;
        for (int i=0; i<n; ++i){
            // scanf("%d", &t[i]);
            t[i] = getNum<int>();
            minTime = min(minTime, t[i]);
        }
        ll low = 0, high = (ll)minTime * m;
        while (high - low > 1) {
            ll mid = (low + high) / 2;
            (enough(mid) ? high : low) = mid;
        }
        printf("%lld\n", high);
    }
    return 0;
}
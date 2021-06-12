#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll int
#define indexX second.first
#define indexY second.second
typedef pair<ll, ll> pii;

bool cmp(pair<ll, pii> a, pair<ll, pii> b) {
    if(a.indexY == b.indexY) {
        if (a.indexX == b.indexX) {
            return a.indexY < b.indexY;
        }
        return a.indexX < b.indexX;
    }
    return a.indexX < b.indexX;
}

int main () {
    ll n, a, b;
    vector<pair<ll, pii>> coordinate;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &a, &b);
        coordinate.push_back(make_pair(i+1, make_pair(a,b)));
    }
    
    sort (coordinate.begin(), coordinate.end(), cmp);
    for (int i=0; i<n; i++) {
        printf("%d ", coordinate[i].first);
    }printf("\n");

    return 0;
}
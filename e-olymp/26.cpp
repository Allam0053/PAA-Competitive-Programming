#include <vector>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

bool getFirstFunc (pair<int, int> a, pair<int, int> b){
    return min(a.first, b.second) < min(b.first, a.second);
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pair<int, int> t[n]; //first -> maid time, second -> santa time
    for(int i=0; i<n; i++) {
        // scanf("%d", &t[i].first);
        cin >> t[i].first;
    }
    for(int i=0; i<n; i++) {
        // scanf("%d", &t[i].second);
        cin >> t[i].second;
    }

    sort(t, t+n, getFirstFunc);

    ll timeBufferMaid = 0;
    ll timeBufferMS = 0;

    for(int i=0; i<n; i++) {
        timeBufferMaid = timeBufferMaid + (ll)t[i].first;
        timeBufferMS = (ll)max(timeBufferMaid, timeBufferMS) + (ll)t[i].second;
    }
    cout << timeBufferMS <<endl;

    return 0;
}
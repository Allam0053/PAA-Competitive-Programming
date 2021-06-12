#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;

int main () {
    /*vector of pair
    pair<ll, ll> pairValSum;
    vector<p> vect;
    pairValSum.first = 5;
    pairValSum.second = 100;
    vect.push_back(pairValSum);
    printf("val:%lld  Sum:%lld\n", vect[0].first, vect[0].second);
    */
    vector<vector<ll>> vect;
    for (ll i=0; i<7; i++) {
        vect.push_back({});
        for (ll j=0; j<5; j++) {
            vector<ll>& temp = vect[i];
            temp.push_back(i*5+j);
        }
    }
    for (ll i=0; i<7; i++) {
        for (ll j=0; j<5; j++) {
            printf("%lld ", vect[i][j]);
        }printf("\n");
    }
    return 0;
}
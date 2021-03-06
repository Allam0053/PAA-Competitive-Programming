#include <iostream>
#include <algorithm>
#define ll int

using namespace std;

ll n;
ll a[301];
ll b[301];
pair<ll, ll> m_1[305];
pair<ll, ll> m_2[305];
pair<ll, ll> ans[605];
ll m1;
ll m2;
ll len_ans;
ll cvb;
ll cem;
ll T1,T2;

bool cmp_m1 (pair <ll ,ll > a , pair <ll, ll > b){
    return a.first <= b.first;
}

bool cmp_m2 (pair <ll ,ll > a , pair <ll, ll > b){
    return a.second >= b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(ll i=1; i<=n; i++){
        cin>>a[i];
    }

    for(ll i=1; i<=n; i++){
        cin>>b[i];
    }

    for(ll i=1; i<=n; i++){
        if(a[i] < b[i]){
            m1++;
            m_1[m1] = make_pair(a[i],b[i]);
        }
        else{
            m2++;
            m_2[m2] = make_pair(a[i],b[i]);
        }
    }

    sort(m_1+1 , m_1+m1+1, cmp_m1);
    sort(m_2+1 , m_2+m2+1, cmp_m2);

    for(ll i=1; i<=m1; i++){
        len_ans++;
        ans[len_ans] = make_pair(m_1[i].first , m_1[i].second);
    }

    for(ll i=1; i<=m2; i++){
        len_ans++;
        ans[len_ans] = make_pair(m_2[i].first , m_2[i].second);
    }

    T1 = 0;
    T2 = 0;

    for(ll i=1; i<=len_ans; i++){
        T1 = T1 + ans[i].first;
        T2 = max(T1 , T2) + ans[i].second;
    }
    
    cout << T2 << endl;

    return 0;
}
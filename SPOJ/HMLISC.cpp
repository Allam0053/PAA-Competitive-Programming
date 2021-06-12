#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pii;
ll MOD = 1000000007;
ll len = 1;
ll n;

template <typename T>
T getNum() {
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

// Binary search
long long GetCeilIndex(long long arr[], vector<long long>& T, long long* key) {
	ll l = -1; 
	ll r = len - 1;
	ll m;
    while (r - l > 1) {
        m = l + (r - l) / 2;
        if (arr[T[m]] >= (*key))
            r = m;
        else
            l = m;
    }
  
    return r;
}

ll getCeilValue(vector<pii>& T, long long *key) {
	ll i = (ll)T.size()-1;
    ll sum=0;
    for (; (T[i].first < (*key)) && (i > -1); --i) {
    		sum = (sum + (T[i].second%MOD))%MOD;
    }
    return sum;
}
  
int main() {
    n = getNum<ll>();
    ll arr[n];
    for (ll i=0; i<n; i++) {
        arr[i] = getNum<ll>();
    }
    
    vector<long long> tailIndices(n, 0); // Initialized with 0
    vector<vector<pii>> saveValSum; //saveValSum[i][j].first, i adalah maxlen, j adalah urutan masuknya value, first adalah value, second adalah sum dari seqs yg mungkin
    saveValSum.push_back(vector<pii>());
    saveValSum.push_back(vector<pii>());
    saveValSum[1].push_back( pii( arr[0], 1) );
    
    for (long long i = 1; i < n; i++) {
        if (arr[i] <= arr[tailIndices[0]]) {
            // new smallest value
            tailIndices[0] = i;
            
            saveValSum[1].push_back( pii( arr[i], 1) );
        }
        else if (arr[i] > arr[tailIndices[len - 1]]) {
            // arr[i] wants to extend largest subsequence
            tailIndices[len++] = i;

            saveValSum.push_back(vector<pii>());
            saveValSum[len].push_back( pii( arr[i], getCeilValue(saveValSum[len-1], &arr[i]) ) );
        }
        else {
            // arr[i] wants to be a potential condidate of
            // future subsequence
            // It will replace ceil value in tailIndices
            long long pos = GetCeilIndex(arr, tailIndices, &arr[i]);
  
            tailIndices[pos] = i;

            saveValSum[(pos+1)].push_back( pii( arr[i], getCeilValue(saveValSum[pos], &arr[i]) ) );
        }
    }
    
    ll res=0;
    for (ll i = 0; i<saveValSum[len].size(); i++) {
    	res = (res + (saveValSum[len][i].second%MOD))%MOD;
    }
    printf("%lld %lld\n", len, res);
  
    return 0;
}

// declare:
//     MOD = 1000000007, len = 1, n: long long

// // Binary search
// GetCeilIndex(arr[]: long long , vector<long long> T, key: long long)
// 	l = -1
// 	r = len - 1
//     while (r - l > 1) {
//         m = l + (r - l) / 2
//         if arr[T[m]] >= key
//             r = m
//         else
//             l = m
//     }
//     return r


// getCeilValue(vector<pair<long long, long long>> T, key: long long)
// 	i = T.size()-1
//     sum=0
//     while (T[i].first < key) && (i > -1)
//     		sum = (sum + (T[i].second%MOD))%MOD
//             i = i - 1
//     return sum

// main()
//     read n
//     declare:
//         arr[n]: long long
//     for i=0 to n-1
//         read arr[i]
    
//     declare:
//         <vector> tailIndices: long long
//         <vector<vector<pair<long long, long long>>>> saveValSum
//     for i=1 to n-1
//         if arr[i] <= arr[tailIndices[0]]
//             // new smallest value
//             tailIndices[0] = i
//             saveValSum[1].push_back( pii( arr[i], 1) )
//         else arr[i] > arr[tailIndices[len - 1]]
//             // arr[i] wants to extend largest subsequence
//             tailIndices[len] = i
//             len = len + 1
//             saveValSum.push_back(vector<pii>())
//             saveValSum[len].push_back( pii( arr[i], getCeilValue(saveValSum[len-1], arr[i]) ) )
//         else
//             // arr[i] wants to be a potential condidate of
//             // future subsequence
//             // It will replace ceil value in tailIndices
//             long long pos = GetCeilIndex(arr, tailIndices, arr[i])
//             tailIndices[pos] = i
//             saveValSum[(pos+1)].push_back( pii( arr[i], getCeilValue(saveValSum[pos], arr[i]) ) )
    
//     declare: 
//         res=0
//     for i=0 to saveValSum[len].size()
//     	res = (res + (saveValSum[len][i].second%MOD))%MOD;
        
//     write len res
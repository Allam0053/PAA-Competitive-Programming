#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pii;
ll MOD = 1000000007;

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

// Binary search
long long GetCeilIndex(long long arr[], vector<long long>& T, long long l, long long r,
                 long long key)
{
    while (r - l > 1) {
        long long m = l + (r - l) / 2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }
  
    return r;
}
long long getValueStart(vector<pii>& T, long long r,
                 long long key)
{	
    ll l = 0;
	ll m;
    while (l < r) {
        m = (l + r) / 2;
        if (T[m].first >= key)
            l = m+1;
        else
            r = m-1;
    }
  
    return l;
}

ll getCeilValue(vector<pii>& T, long long key) {
	ll r = T.size();
    ll indexBawah = getValueStart(T, r, key);
    ll sum=0;
    for (ll i = indexBawah; i<r; i++) {
    	if (T[i].first<key){
    		sum = (sum + (T[i].second%MOD))%MOD;
    	}
    }
    return sum;
}
  
void LongestIncreasingSubsequence(long long arr[], long long n)
{
    vector<long long> tailIndices(n, 0); // Initialized with 0
    vector<vector<pii>> saveValSum; //saveValSum[i][j].first, i adalah maxlen, j adalah urutan masuknya value, first adalah value, second adalah sum dari seqs yg mungkin
    saveValSum.push_back(vector<pii>());
    saveValSum.push_back(vector<pii>());
    saveValSum[1].push_back( pii( arr[0], 1) );
    
    long long len = 1; // it will always point to empty location
    
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
            saveValSum[len].push_back( pii( arr[i], getCeilValue(saveValSum[len-1], arr[i]) ) );
        }
        else {
            // arr[i] wants to be a potential condidate of
            // future subsequence
            // It will replace ceil value in tailIndices
            long long pos = GetCeilIndex(arr, tailIndices, -1,
                                   len - 1, arr[i]);
  
            tailIndices[pos] = i;

            saveValSum[(pos+1)].push_back( pii( arr[i], getCeilValue(saveValSum[pos], arr[i]) ) );
        }
    }
    
    ll res=0;
    for (ll i = 0; i<saveValSum[len].size(); i++) {
    	res = (res + (saveValSum[len][i].second%MOD))%MOD;
    }
    printf("%lld %lld\n", len, res);
    
    return;
}
  
int main()
{
    // int arr[] = { 1, 3, 2, 5, 4 };
    // int n = sizeof(arr) / sizeof(arr[0]);
    // added the two lines below
    
    ll n;
    // cin >> n;
    n = getNum<ll>();
    ll arr[n];
    for (ll i=0; i<n; i++) {
        arr[i] = getNum<ll>();
    }
    
    LongestIncreasingSubsequence(arr, n);
  
    return 0;
}

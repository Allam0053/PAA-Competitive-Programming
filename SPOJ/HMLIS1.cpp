#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
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
  
void LongestIncreasingSubsequence(long long arr[], long long n)
{
    // Add boundary case, when array n is zero
    // Depend on smart pointers
  
    vector<long long> tailIndices(n, 0); // Initialized with 0
    vector<long long> prevIndices(n, -1); // initialized with -1
    vector<long long> maxLen(n, 1);
    bool flag = false;
  
    long long len = 1; // it will always point to empty location
    for (long long i = 1; i < n; i++) {
        if (arr[i] < arr[tailIndices[0]]) {
            // new smallest value
            tailIndices[0] = i;
            maxLen[i] = 1;
        }
        else if (arr[i] > arr[tailIndices[len - 1]]) {
            // arr[i] wants to extend largest subsequence
            prevIndices[i] = tailIndices[len - 1];
            tailIndices[len++] = i;

            maxLen[i] = len;
            flag = true;
        }
        else {
            // arr[i] wants to be a potential condidate of
            // future subsequence
            // It will replace ceil value in tailIndices
            long long pos = GetCeilIndex(arr, tailIndices, -1,
                                   len - 1, arr[i]);
  
            prevIndices[i] = tailIndices[pos - 1];
            tailIndices[pos] = i;

            maxLen[i] = pos + 1;
        }
    }
    
    long long count = n;
    long long count1 = n;
    if(flag){
        count = 1;
        count1 = 1;

        long long lim = prevIndices[tailIndices[len - 1]];
        long long firstMultiple = 1, lastMultiple = 1;
        for (long long i = tailIndices[len - 1]-1; i>lim; i--) {
            if (arr[i] >= arr[tailIndices[len - 1]])
                firstMultiple++;
        }
        // count = count * firstMultiple;
        // // count = count % MOD;
        count1 = count1 * firstMultiple;
        
        long long lastRight;
        for (long long i = tailIndices[len - 1]; i>=0; i = prevIndices[i]) {
            long long left, curr, right, multiple;
            left = prevIndices[i];
            left = prevIndices[left];
            curr = prevIndices[i];
            right = i;
            if (left<0 || 100000<=left) {
                lastRight = curr;
                break;
            }
            
            multiple = 1;
            for(long long j = curr - 1; j > left; j--) {
                if ((arr[left] < arr[j] && arr[j] <= arr[right]) &&
                    (maxLen[curr] == maxLen[right]-1))
                        multiple++;
            }
            // // count = count * multiple;
            // // count = count % MOD;
            count1 = count1 * multiple;
        }
        
        // printf("lastR: %lld\n", lastRight);
        for (long long i = lastRight-1; i>=0; i--) {
            if (arr[i] >= arr[lastRight])
                lastMultiple++;
        }
        // for (long long i = 0; i<lastRight; i++) {
        //     if (arr[i] >= arr[lastRight])
        //         cout << arr[i] << endl;
        // }
        // // count = count * lastMultiple;
        // // count = count % MOD;
        count1 = count1 * lastMultiple;
    }
    // // count = count % MOD;
    count1 = count1 % MOD;
    len =  len % MOD;
    cout << len << " " << count1 << "\n";
    // printf("%lld %lld\n", len, count1);
  
    // return len;
}
  
int main()
{
    // int arr[] = { 1, 3, 2, 5, 4 };
    // int n = sizeof(arr) / sizeof(arr[0]);
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    LongestIncreasingSubsequence(arr, n);
  
    return 0;
}

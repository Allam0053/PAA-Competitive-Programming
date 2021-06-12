#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
/*
ll batasBawahCombination (vector<ll>& savePosP, ll l, ll r, ll key) {
    while (r - l > 1) {
        long long m = l + (r - l) / 2;
        if (savePosP[m] > key)
            r = m;
        else
            l = m;
    }
  
    return l;
}

ll batasAtasCombination (ll arr[], vector<ll>& savePosP, ll l, ll r, ll key) {
    while (r - l > 1) {
        long long m = l + (r - l) / 2;
        if (arr[savePosP[m]] > arr[key])
            r = m;
        else
            l = m;
    }
  
    return r;
}
*/
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
    
    // bool flag = false;
    
    long long len = 1; // it will always point to empty location
    
    for (long long i = 1; i < n; i++) {
        if (arr[i] < arr[tailIndices[0]]) {
            // new smallest value
            tailIndices[0] = i;
            maxLen[i] = 1;
            // if (savePos.size()-1 < 1) savePos.push_back({});
            // savePos[1].push_back(i);
            // saveCombination[1].push_back(0);
        }
        else if (arr[i] > arr[tailIndices[len - 1]]) {
            // arr[i] wants to extend largest subsequence
            prevIndices[i] = tailIndices[len - 1];
            tailIndices[len++] = i;

            maxLen[i] = len;
            // if (savePos.size()-1 < len) savePos.push_back({});
            // savePos[len].push_back(i);
            // saveCombination[len].push_back(0);
            // flag = true;
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
            // if (savePos.size()-1 < pos + 1) savePos.push_back({});
            // savePos[pos + 1].push_back(i);
            // saveCombination[pos + 1].push_back(0);
        }
    }
    
    vector<ll> savePos[len+1];
    vector<ll> saveCom[len+1];
    vector<ll> sizeInit(len + 1, 0);
    saveCom[0].push_back(0);
    // cout << saveCom[0][0] << endl;
    // for (long long i = 0; i < n; i++) cout << arr[i] << " "; cout << endl;
    for (long long i = 0; i < n; i++) {
        ll index = maxLen[i];
        savePos[index].push_back(i);
        saveCom[index].push_back(0);
        sizeInit[index] += 1;
        // if (arr[i]>9) cout << " " << index << " ";
        // else cout << index << " ";
        // cout << "sizeInit[" << index << "] = " << sizeInit[index] << endl;
    }
    // cout << endl;
    // cout << "saveCom[0][0]" << " = " << saveCom[0][0] << endl;
    // for (long long i = 0; i < sizeInit.size(); i++) {
    //     cout << sizeInit[i] << " ";
    // } 
    for (long long i = 0; i < sizeInit[len-1]; i++) {
        saveCom[len][i] = 1;
    }

    // for (ll i = 0; i<len+1; i++) {
    //     for (ll j = 0; j<sizeInit[i]; j++) {
    //         cout << savePos[i][j] << " ";
    //     }cout << endl;
    // }
    
    // for (ll i = 0; i<len+1; i++) {
    //     for (ll j = 0; j<sizeInit[i]; j++) {
    //         cout << saveCom[i][j] << " ";
    //     }cout << endl;
    // }
    
    for (ll i = len-1; i>=0; i--) {
        for (ll j = 0; j<sizeInit[i]; j++) {
            for(ll k = 0; k<sizeInit[i+1]; k++) {
            	// if (i==1) {
            	// 	cout << "arr[savePos[i][j]] = " << arr[savePos[i][j]] << " < " << arr[savePos[i+1][k]] << " = arr[savePos[i+1][k]] " << "&&" << endl;
            	// 	cout << "savePos[i][j] = " << savePos[i][j] << " < " << savePos[i+1][k] << " = savePos[i+1][k]" << endl;
            	// 	cout << endl;
            	// }
                if ( (arr[savePos[i][j]] < arr[savePos[i+1][k]]) &&  //segment fauult
                     (savePos[i][j] < savePos[i+1][k])) {
                        saveCom[i][j] += saveCom[i+1][k]; 
                }
            }
            // cout << "tes\n";
        }
    }
    ll res = 0;
    for (ll i = 0; i<sizeInit[1]; i++) {
    	res += saveCom[1][i];
    }
    
    // cout << res << endl;
    // for (ll i = 1; i<len+1; i++) {
    //     for (ll j = 0; j<sizeInit[i]; j++) {
    //     	cout << saveCom[i][j] << " ";
    //     }cout << endl;
    // }

    cout << len%MOD << " " << res%MOD << endl;
    
    // ll saveCombiLen = saveCombination.size();
    // saveCombination[saveCombiLen-1][saveCombination[saveCombiLen].size()] = 1;
    // saveCombination[0][0] = 1;
    // for (ll i = savePos.size()-1; i>=0; i--) {
    //     for (ll j = 0; j<savePos[i].size(); j++) {
    //         ll bawah = batasBawahCombination(savePos[i+1], 0, savePos[i+1].size(), savePos[i][j]);
    //         ll atas = batasAtasCombination(arr, savePos[i+1], 0, savePos[i+1].size(), savePos[i][j]);
    //         for (ll k = bawah; k<atas; k++) {
    //             // if ( (arr[savePos[i][j]] < arr[savePos[i+1][k]]) && 
    //             //      (savePos[i][j] < savePos[i+1][k])) {
    //                     saveCombination[i][j] += saveCombination[i+1][k];
    //             // }
    //         }
    //     }
    // }

    // for (ll i = 0; i < saveCombination.size(); i++) {
    //     for (ll j = 0; j<saveCombination[i].size(); j++) {
    //         cout << saveCombination[i][j] << " ";
    //     }cout << endl;
    // }
    // for (ll i = 0; i < 3; i++) {
    //     for (ll j = 0; j<1; j++) {
    //         cout << savePos[i][j] << " ";
    //     }cout << endl;
    // }
    // cout << "tes" << endl;
    
    // long long count = n;
    // if(flag){
        
    // }
    // saveCombination[0][0] = saveCombination[0][0] % MOD;
    // len =  len % MOD;
    // cout << len << " " << savePos[0][0] << "\n";
    // printf("%lld %lld\n", len, count1);
  
    // return len;
    return;
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

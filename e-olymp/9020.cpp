// C++ implemenattion of the above approach
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to check if mid can
// be maximum sub - arrays sum
bool check(ll mid, ll array[], ll n, ll K)
{
	ll count = 0;
	ll sum = 0;
	for (ll i = 0; i < n; i++) {

		// If individual element is greater
		// maximum possible sum
		if (array[i] > mid)
			return false;

		// Increase sum of current sub - array
		sum += array[i];

		// If the sum is greater than
		// mid increase count
		if (sum > mid) {
			count++;
			sum = array[i];
		}
	}
	count++;

	// Check condition
	if (count <= K)
		return true;
	return false;
}

// Function to find maximum subarray sum
// which is minimum
ll solve(ll array[], ll n, ll K)
{
	ll* max = max_element(array, array + n);
	ll start = *max;
	ll end = 0;

	for (ll i = 0; i < n; i++) {
		end += array[i];
	}

	// Answer stores possible
	// maximum sub array sum
	ll answer = 0;
	while (start <= end) {
		ll mid = (start + end) / 2;

		// If mid is possible solution
		// Put answer = mid;
		if (check(mid, array, n, K)) {
			answer = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return answer;
}

// Driver Code
int main(){
	// ll array[] = { 1, 2, 3, 4 };
	// ll n = sizeof(array) / sizeof(array[0]);
	// ll K = 3;
    ll n,K;
    scanf("%lld%lld", &n,&K);
    ll array[n];
    for (ll i=0; i<n; i++) {
        scanf("%lld", &array[i]);
    }
	cout << solve(array, n, K) << endl;
}

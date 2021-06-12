#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

ll countLessThan(ll *arrayA, ll length, ll currentBi) {
	ll leftOfBST = 0, rightOfBST = length - 1;
	ll indexOfLessThanBi = -1;

	// Modified binary search
	while (leftOfBST <= rightOfBST) {
		ll midOfBST = (leftOfBST + rightOfBST) / 2;

		if (arrayA[midOfBST] < currentBi) {
			leftOfBST = midOfBST + 1;
			indexOfLessThanBi = midOfBST;
		} else {
			rightOfBST = midOfBST - 1;
		}
	}

	return (indexOfLessThanBi + 1);
}

ll countGreaterThan(ll *arrayC, ll length, ll currentBi) {
	ll leftOfBST = 0, rightOfBST = length - 1;
	ll indexOfMoreThanBi = -1;

	// Modified binary search
	while (leftOfBST <= rightOfBST) {
		ll midOfBST = (leftOfBST + rightOfBST) / 2;

		if (arrayC[midOfBST] <= currentBi) {
			leftOfBST = midOfBST + 1;
		} else {
			rightOfBST = midOfBST - 1;
			indexOfMoreThanBi = midOfBST;
		}
	}

	if (indexOfMoreThanBi == -1)
		return 0;
	return (length - indexOfMoreThanBi);
}

int main () {
    ll length;
    scanf("%lld", &length);
    ll arrayA[length], arrayB[length], arrayC[length];

    for (ll i=0; i<length; i++) scanf("%lld", &arrayA[i]);
	for (ll i=0; i<length; i++) scanf("%lld", &arrayB[i]);
	for (ll i=0; i<length; i++) scanf("%lld", &arrayC[i]);

    sort(arrayA, arrayA+length);
    sort(arrayB, arrayB+length);
    sort(arrayC, arrayC+length);

    ll combination = 0;
    for (ll i=0; i<length; i++) {
        ll currentBi = arrayB[i];
        ll a_index = -1, c_index = -1;

        ll lessThanBi = countLessThan(arrayA, length, currentBi);
        ll moreThanBi = countGreaterThan(arrayC, length, currentBi);

        combination += (lessThanBi * moreThanBi);
    }

    printf("%lld\n", combination);

    return 0;
}
#include <stdio.h>
typedef long long ll;
int main () {
    ll number;
    scanf("%lld", &number);
    for(ll i=2; i*i<number; i++) {
        if (number%i == 0) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
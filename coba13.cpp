#include <stdio.h>
#include <iostream>
using namespace std;
#define ull unsigned long long
// Function to return gcd of a and b
ull gcd(ull a, ull b)
{
    // Base Case
    if (a == 0)
        return b;
 
    // Recursive GCD
    return gcd(b % a, a);
}
 
// Function to find the product of
// all the numbers till N that are
// relatively prime to N
ull findProduct(ull N)
{
    // Stores the resultant product
    ull result = 1;
 
    // Iterate over [2, N]
    for (ull i = 2; i < N; i++) {
 
        // If gcd is 1, then find the
        // product with result
        if (gcd(i, N) == 1) {
            result *= (i%N);
        }
 
        
    }
   // Return the final product
        return result;
}
 
// Driver Code
int main()
{
    ull N;
    scanf("%llu", &N);
    if(!N){printf("1\n"); return 0;}
    else if(N%4==0 && N>4){printf("1\n"); return 0;}
    printf("%llu\n", (findProduct(N)%N));
    // cout << findProduct(N);
    return 0;
}
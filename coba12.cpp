#include <stdio.h>
#include <algorithm>
using namespace std;
#define ull long long unsigned

// // Function to return gcd of a and b
// ull gcd(ull a, ull b)
// {
//     // Base Case
//     if (a == 0)
//         return b;
 
//     // Recursive GCD
//     return gcd(b % a, a);
// }
 
// // Function to find the product of
// // all the numbers till N that are
// // relatively prime to N
// ull findProduct(ull N)
// {
//     // Stores the resultant product
//     ull result = 1;
 
//     // Iterate over [2, N]
//     for (ull i = 2; i < N; i++) {
 
//         // If gcd is 1, then find the
//         // product with result
//         if (gcd(i, N) == 1) {
//             result *= i;
//         }
 
        
//     }
//    // Return the final product
//         return result;
// }
 
// // Driver Code
// int main()
// {
//     ull N;
//     scanf("%llu", &N);
 
//     printf("%llu\n", (findProduct(N)%N));
//     return 0;
// }

ull coprimef (ull m, ull n){
    if(__gcd(m,n)==1)
        return n;
    else return 0;
}

// int main(){
//     ull m, product=1, coprime;
//     scanf("%d", &m);
//     if(m==0){printf("1\n"); return 0;}
//     if(m==1){printf("0\n"); return 0;}
//     for(ull i=2; i<m; i++){
//         coprime = coprimef(m,i);
//         if(coprime)
//             product *= (coprime%m);
//     }
//     printf("%d\n", product);
//     return 0;
// }
 
// modulo function to perform binary exponentiation
ull modulo(ull base, ull exponent,
                                      ull mod)
{
    ull x = 1;
    ull y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
 
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
 
    return x % mod;
}
 
// // To calculate Jacobian symbol of a given number
ull calculateJacobian(ull a, ull n)
{
    if (!a)
        return 0;// (0/n) = 0
 
    ull ans = 1;
    if (a < 0)
    {
        a = -a; // (a/n) = (-a/n)*(-1/n)
        if (n % 4 == 3)
            ans = -ans; // (-1/n) = -1 if n = 3 (mod 4)
    }
 
    if (a == 1)
        return ans;// (1/n) = 1
 
    while (a)
    {
        if (a < 0)
        {
            a = -a;// (a/n) = (-a/n)*(-1/n)
            if (n % 4 == 3)
                ans = -ans;// (-1/n) = -1 if n = 3 (mod 4)
        }
 
        while (a % 2 == 0)
        {
            a = a / 2;
            if (n % 8 == 3 || n % 8 == 5)
                ans = -ans;
 
        }
 
        swap(a, n);
 
        if (a % 4 == 3 && n % 4 == 3)
            ans = -ans;
        a = a % n;
 
        if (a > n / 2)
            a = a - n;
 
    }
 
    if (n == 1)
        return ans;
 
    return 0;
}
 
// // To perform the Solovay-Strassen Primality Test
bool solovoyStrassen(ull p, ull iterations)
{
    if (p < 2)
        return false;
    if (p != 2 && p % 2 == 0)
        return false;
 
    for (ull i = 0; i < iterations; i++)
    {
        // Generate a random number a
        long long a = rand() % (p - 1) + 1;
        long long jacobian = (p + calculateJacobian(a, p)) % p;
        long long mod = modulo(a, (p - 1) / 2, p);
 
        if (!jacobian || mod != jacobian)
            return false;
    }
    return true;
}
 
// // Driver Code
int main()
{
    ull iterations = 50;
    ull m, product=1, coprime;
    scanf("%llu", &m);
    if(m==0){printf("1\n"); return 0;}
    else if(m==1){printf("0\n"); return 0;}
    else if (solovoyStrassen(m, iterations) || m<7)
        // for(ull i=2; i<m; i++){
        //     product *= (i%m);
        printf("%llu\n", m-1);
    // }
    else if(true){} //missing conditions
    else printf("1\n");
    // for(ull i=2; i<m; i++){
    //     coprime = coprimef(m,i);
    //     if(coprime)
    //         product *= (coprime%m);
    // }

    return 0;
}
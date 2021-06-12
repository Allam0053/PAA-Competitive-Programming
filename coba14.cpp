#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define ull long long unsigned

ull coprimef (ull m, ull n){
    if(__gcd(m,n)==1)
        return n;
    else return 0;
}
 
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
        printf("%llu\n", m-1);
    else if(m%4==0 || m%5==0 || (m%3==0 && m>20)){printf("1\n"); return 0;} //missing some conditions
    else printf("%llu\n", m-1);
    

    return 0;
}


// bool afterprime(unsigned long long N){
//     N--;
//     bool flag=true;
//     for(unsigned long long i=2; i*i<=N; i++)
//         if(N%i==0)return false;
//     return flag;
// }

// void checkprime(unsigned long long N){
//     for(unsigned long long i=2; i*i<=N; i++){
//         if(N%i==0){printf("1\n"); return;} //jika bukan prime
//         if( (N%(N/i)) == 0 ){printf("1\n"); return;}
//     }
//     printf("%llu\n", N-1); //jika prime
//     return;
// }

// int main(){
//     unsigned long long N,ans=1;
//     scanf("%llu", &N);
//     if(!N){printf("1\n"); return 0;}
//     else if(N%4==0 && N>4){printf("1\n"); return 0;}
//     else if(4<N && N<8){printf("%llu\n", N-1); return 0;}
//     else if( afterprime(N) ){printf("1\n"); return 0;}
//     else checkprime(N);
    
//     return 0;
// }
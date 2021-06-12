// #include <cstdio>
// #include <cmath>
 
// #define MAX 1000000
 
// using namespace std;
 
// static int num[ MAX + 1 ];
// static unsigned long long dp[ MAX + 1 ];

// int main(void)
// {
// 	int K;
// 	for(int i=1; i<=MAX; i++) {
// 		for(int j=2*i; j<=MAX; j+=i) {
// 			num[j]+=i;
// 		}
// 	}
// 	for( int i = 2; i <= MAX; i++ ) {
// 		dp[ i ] = dp[ i - 1 ] + num[ i ];
// 	}
// 	scanf("%d",&K);
// 	while( K-- ) {
// 		int N;
// 		scanf("%d",&N);
// 		printf("%llu\n", dp[ N ] );
// 	}
// 	return 0;
// }

#include <stdio.h>
#define uul unsigned long long
uul a[1000001];
int main (){
    int T, N;
    for(int i=1; i<=1000000; i++){
        for(int j=2*i; j<=1000000; j+=i)
            a[j]+=i;
        a[i] += a[i-1];
    }
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        printf("%llu\n", a[N]);
    }
    return 0;
}

// #include <bits/stdc++.h>
// #include <stdio.h>
// #define uul unsigned long long
// using namespace std;
 
// // Driver Code
// int main()
// {
//     // cout << "tes" << endl;
//     // uul n,T;
//     // SieveOfEratosthenes(1000000);
//     // scanf("%llu", &T);
//     // while(T--){
//     //     scanf("%llu", &n);
//     //     printf("%llu\n", a[n]);
//     // }
//     uul N = 1000000;
//     uul lp[N+1];
//     vector<unsigned long long> pr;
//     for (uul i=2; i<=N; ++i) {
//         if (lp[i] == 0) {
//             lp[i] = i;
//             pr.push_back (i);
//         }
//         for (uul j=0; j<(uul)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
//             lp[i * pr[j]] = pr[j];
//     }
//     for(uul i=0; i<100;i++){
//         printf("%d\n", pr[i]);
//     }
 
//     return 0;
// }
// // A Better (than Naive) Solution to find all divisiors
// #include <bits/stdc++.h>
// #define uul unsigned long long
// // Function to print the divisors
// uul a[1000000]={0};
// int defined=2;
// uul sum_of_divisor(uul n)
// {
//     // Note that this loop runs till square root
//     uul result=0;
//     for (int i=1; i<=sqrt(n); i++)
//     {
//         if (n%i == 0)
//         {
//             // If divisors are equal, print only one
//             if (n/i == i)
//                 // printf("%d ", i);
//                 result+=i;
 
//             else // Otherwise print both
//                 // printf("%d %d ", i, n/i);
//                 result+= (i+ (n/i));
//         }
//     }
//     result-=n; // karena n masuk ke dalam sum maka kurangi n
//     return result;
// }
 
// /* Driver program to test above function */
// int main()
// {
//     int T;
//     uul n;
//     scanf("%d", &T);
//     a[0]=0;
//     a[1]=0;
//     // for(int i=2;i<1000000;i++){
//     //     a[i]=a[i-1]+sum_of_divisor(i);
//     // }
//     while(T--){
//         scanf("%llu", &n);
//         if(!a[n]){ //jika kosong
//             uul i;
//             for( i=defined; i<=n; i++){
//                 defined++;
//                 a[i]=a[i-1]+sum_of_divisor(i);
//             }
//         }
//         printf("%llu\n", a[n]);
//     }
    
//     return 0;
// }


// C++ program to print all primes
// smaller than or equal to
// n using Sieve of Eratosthenes
// bool prime[1000000];
// uul a[1000000];

// uul sum_of_divisor(uul n)
// {
//     // Note that this loop runs till square root
//     uul result=0;
//     for (int i=1; i<=sqrt(n); i++)
//     {
//         if (n%i == 0)
//         {
//             // If divisors are equal, print only one
//             if (n/i == i)
//                 // printf("%d ", i);
//                 result+=i;
 
//             else // Otherwise print both
//                 // printf("%d %d ", i, n/i);
//                 result+= (i+ (n/i));
//         }
//     }
//     result-=n; // karena n masuk ke dalam sum maka kurangi n
//     return result;
// }
 
// void SieveOfEratosthenes(uul n)
// {
//     // Create a boolean array
//     // "prime[0..n]" and initialize
//     // all entries it as true.
//     // A value in prime[i] will
//     // finally be false if i is
//     // Not a prime, else true.
//     memset(prime, true, sizeof(prime));
 
//     for (uul p = 2; p * p <= n; p++)
//     {
//         // If prime[p] is not changed,
//         // then it is a prime
//         if (prime[p] == true)
//         {
//             // Update all multiples
//             // of p greater than or
//             // equal to the square of it
//             // numbers which are multiple
//             // of p and are less than p^2
//             // are already been marked.
//             for (uul i = p * p; i <= n; i += p){
//                 prime[i] = false;
//             }
//         }
//     }
 
//     // Pruul all prime numbers
//     for (uul p = 2; p <= n; p++)
//         if (prime[p])
//             a[p]=a[p-1]+1;
//         else a[p]=a[p-1]+sum_of_divisor(p);
// }
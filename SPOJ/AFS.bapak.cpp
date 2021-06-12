#include <stdio.h>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
// template <typename T>
// T getNum(){
//     T res = 0;
//     char c;
//     while(1){
//         c=getchar_unlocked();
//         if(c==' ' || c=='\n')continue;
//         else break;
//     }
//     res=c-'0';
//     while(1){
//         c=getchar_unlocked();
//         if(c>='0'&&c<='9')res=10*res+c-'0';
//         else break;
//     }
//     return res;
// }
int main (){
	int T;
	LL n, a, a1, a2, ans, sum;
	scanf("%d", &T);
	while(T--){
		// n=getNum<LL>();
		scanf("%d", &n);
		ans=0;
		for(a=2; a*a<=n; ++a){//19 biggest divisor e => 4... a <= sqrt(n)
			//karena setiap pembagian n dengan a mempunyai hasil n/a dimana n=ad+r dimana d adalah hasil bagi dan r adalah sisa.
			a1=a;//2, 3, 4
			a2=n/a;//9, 6, 4
			if(a1<=a2){
				//setiap a dimana a adalah 2 sampai dengan sqrt n, jumlahkan pembagi2 dari bilangan kurang dari sama dengan n
				//a1 digunakan untuk mendapatkan jumlah dari bilangan2 kurang dari sama dengan n yang bisa dibagi dengan a
				//a2 digunakan untuk mendapatkan jumlah dari bilangan2 kurang dari sama dengan n yang bisa dibagi dengan n/a
				sum= (a2 * (a2 + 1)) / 2 - (a1 * (a1+1))/ 2;
				ans+=sum;
				ans+= a*(a2-a1);
			}
			ans+=a;
		}
		ans+=n-1;
		printf("%lld\n",ans);
	}
	return 0;
}
// while(T--){
// 		n=getNum<LL>();
// 		ans=0;
// 		for(a=2; a*a<=n; ++a){
// 			a1=(a+1);
// 			a2=n/a;
// 			if(a1<=a2){
// 				sum= (a2 * (a2 + 1)) / 2 - (a1 * (a1-1))/ 2;
// 				ans+=sum;
// 				ans+= a*(a2-a1+1);
// 			}
// 			ans+=a;
// 		}
// 		ans+=n-1;
// 		printf("%lld\n",ans);
// 	}

// declare:
// 	T,n,a,a1,a2,ans,sum : integer

// read T
// while T>0
// 	read n

// 	//inisiasi agar pada tiap awal komputasi 
// 	//pada kasus uji yang berbeda tidak melibatkan 
// 	//perhitungan kasus uji sebelumnya
// 	ans=0 

// 	for a=2 to root(n) //root return sqrt of n
// 		a1=a
// 		a2=n/a
// 		if a1<=a2
// 			ans= ans+(a2 * (a2 + 1)) / 2 - (a1 * (a1+1))/ 2
// 			ans= ans+a*(a2-a1)
// 		ans= ans+a
// 	ans= ans+n-1
// 	write ans


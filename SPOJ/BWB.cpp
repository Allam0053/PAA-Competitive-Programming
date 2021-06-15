#include <stdio.h>
#define MOD 1000000007
template <typename T>
T getNum(){
    T res = 0;
    char c;
    while(1){
        c=getchar_unlocked();
        if(c==' ' || c=='\n')continue;
        else break;
    }
    res=c-'0';
    while(1){
        c=getchar_unlocked();
        if(c>='0'&&c<='9')res=10*res+c-'0';
        else break;
    }
    return res;
}

int dp[101][10001];
int main () {
    int pow[100001];
    pow[0] = 1;
    pow[1] = 2 % MOD;
    for (int i = 2; i <= 100000; i++) {
        pow[i] = (pow[i - 1] * 2) % MOD;
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 10000; j++) {
            if (i > j) {
                dp[i][j] = 0;
                continue;
            } else if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            int temp = pow[j - (i + 1)] - dp[i][j - (i + 1)];
            if (temp < 0) temp += MOD;
            dp[i][j] = ((2 * dp[i][j-1]) % MOD + temp) % MOD;
        }
    }
    int T,N,K;
    T = getNum<int>();
    while (T--) {
        N = getNum<int>();
        K = getNum<int>();
        int temp = pow[N - 1] - dp[K][N - 1];
        if (temp < 0) temp += MOD;
        printf("%d\n", temp);
    }
}


/*

pada problem ini program harus dapat menghitung jumlah konfigurasi penyusunan black and white beads yang mungkin dan valid. Konfigurasi tidak valid bila terdapat K black beads berturut-turut.
Untuk dapat menghitung jumlah konfigurasi yang mungkin maka harus dihitung jumlah konfigurasi yang tidak valid. Konfigurasi yang didapatkan dari penyusunan tanpa persyaratan adalah 2 ^ n. maka dari itu bila seluru jumlah konfigurasi dikurangkan dengan jumlah konfigurasi yang tidak valid maka akan didapat konfigurasi yang valid.

perhitungan jumlah konfigurasi yang tidak valid akan membentuk sebuah keteraturan.
pertama, bila K lebih besar dari N maka jumlah konfigurasi ada valid adalah semua konfigurasi maka konfigurasi tidak valid ada 0
kedua, bila jumlah K sama dengan N maka jumlah konfigurasi ada 2 ^ N - 1 maka konfigurasi tidak valid ada 1
ketiga, bila jumlah K kurang dari N maka jumlah konfigurasi yang tidak valid ada sejumlah konfigurasi tidak valid dari panjang N-1 dikali 2 ditambah dengan konfigurasi valid dari panjang N - K - 1. Karena konfigurasi panjang N didapat dari konfigurasi panjang N-1 dan ditambahkan salah satu dari beads hitam atau putih dibagian depannya. Lalu penambahan konfigurasi valid dari N - K - 1 itu karena bila konfigurasi tersebut ditambah atau digabung dengan kemunculan konfigurasi diluar dari konfigurasi tidak valid dari panjang N-1 dikali 2 yang sebelumnya akan terbentuk konfigurasi tidak valid untuk N.

Jadi ada 2 recurrence untuk persoalan ini yaitu kemunculan konfigurasi tidak valid panjang N dari penggabungan 0 atau 1 pada depan konfigurasi panjang N - 1 dan konfigurasi tidak valid karena adanya konfigurasi valid dari N - K - 1.

*/

// define MOD 1000000007

// Template <Typename T>
// getNum()
//  res = 0
//  while (true)
//   c=getchar_unlocked()
//   if c==' ' || c=='\n'
//    continue
//   else
//    break
//  res=c-'0'
//  while (true)
//   c=getchar_unlocked()
//   if c>='0' && c<='9'
//    res=10*res+c-'0'
//   else
//    break
//  return res
 
// dp[101][10001]
// main()
//  pow[100001]
//  pow[0] = 1
//  pow[1] = 2 mod MOD
//  for i=2 to 100000
//   pow[i] = (pow[i-1] * 2) mod MOD
//  for i = 1 to 100
//   for i = 1 to 10000
//    if i > j
//     dp[i][j] = 0
//     continue
//    else if i == j
//     dp[i][j] = 1
//     continue
//    temp = pow[j -(i+1)] - dp[i][j] - (i + 1)
//    if temp < 0
//     temp = temp + MOD
//    dp[i][j] = ((2 * dp[i][j-1]) mod MOD + temp) mod MOD
//  T = getNum<int>()
//  while T > 0
//   N = getNum<int>()
//         K = getNum<int>()
//         temp = pow[N - 1] - dp[K][N - 1]
//         if temp < 0
//    temp = temp + MOD
//         print temp
//         T = T - 1
        
//     SPOJ 19545
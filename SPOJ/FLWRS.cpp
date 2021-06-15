#include <iostream>
using namespace std;
typedef long long ll;

ll orders[2020];
ll n, m;

int main () {
    ll t1, t2, t3, t4;
    int i, hasil;
    cin >> n >> m;
    orders[0] = 1; orders[1] = 1; orders[2] = 0; orders[3] = 0;
    if (n > 3) {
        for (i = 4; i <= n; i++) {
            t1 = ((i+1)%m * orders[i-1])%m;
            t2 = ((i-2)%m * orders[i-2])%m;
            t3 = ((i-5)%m * orders[i-3])%m;
            t4 = ((i-3)%m * orders[i-4])%m;
            orders[i] = (t1 - t2 - t3 + t4) % m;
        }
    }
    hasil = (int) orders[n] % m;
    while (hasil < 0) hasil += m;
    printf("%d\n", hasil);
    return 0;
}

/*

pada problem ini, program harus dapat menghitung jumlah konfigurasi dimana jumlah konfigurasi dihitung dari jumlah pemindahan yang mungkin dilakukan dengan syarat pemindahan pot dimana pot yang pada awalnya bersebalahan maka tidak boleh bersebelahan lagi
misal
ABCDE
maka peraturannya adalah AB, BC, CD, DE tidak boleh bersebelahan.
dengan kata lain konfigurasi yang mengandung
AB, BC, CD, DE, ED, DC, CB, BA 
adalah konfigurasi yang salah.
untuk soal ini diperlukan referensi dari jurnal yang ada sehingga ditemukan keteraturannya.
jika panjang atau banyak pot lebih dari 4 maka akan dilakukan looping untuk menghitung konfigurasi yang muncul karena recurrence dari 4 konfigurasi sebelumnya.
a(n) = (n+1)*a(n-1) - (n-2)*a(n-2) - (n-5)*a(n-3) + (n-3)*a(n-4)

*/
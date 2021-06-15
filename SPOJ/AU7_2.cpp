#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAXN 100002
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
int n; //jumlah komputer
int m; //jumlah proses
int t[MAXN];
bool enough (ll time) {
    ll cnt = 0;
    for (int i=0; i<n; ++i) {
        ll here = time / t[i];
        if (here >= m || here + cnt >= m)
            return true;
        cnt += here;
    }
    return cnt >= m;
}

int main () {
    int T;
    // scanf("%d", &T);
    T = getNum<int>();
    while (T--) {
        // scanf("%d%d", &n, &m);
        n = getNum<int>();
        m = getNum<int>();
        int minTime = 1000000000;
        for (int i=0; i<n; ++i){
            // scanf("%d", &t[i]);
            t[i] = getNum<int>();
            minTime = min(minTime, t[i]);
        }
        ll low = 0, high = (ll)minTime * m;
        while (high - low > 1) {
            ll mid = (low + high) / 2;
            (enough(mid) ? high : low) = mid;
        }
        printf("%lld\n", high);
    }
    return 0;
}

// define MAXN 100002

// Template <Typename T>
// getNum()
// 	res = 0
// 	while (true)
// 		c=getchar_unlocked()
// 		if c==' ' || c=='\n'
// 			continue
// 		else
// 			break
// 	res=c-'0'
// 	while (true)
// 		c=getchar_unlocked()
// 		if c>='0' && c<='9'
// 			res=10*res+c-'0'
// 		else
// 			break
// 	return res


// t[MAXN]

// enough (time)
// 	cnt = 0
// 	for i=0 to n-1
// 		here = time / t[i]
// 		if here >= m || here + cnt >= m
// 			return true
// 		cnt = cnt + here
// 	return cnt >= m


// main()
// 	T = getNum<int>()
// 	while T>0
// 		n = getNum<int>()
//         m = getNum<int>()
//         minTime = 1000000000
//         for i=0 to n-1
//         	t[i] = getNum<int>()
//         	minTime = min(minTime), t[i]
//         low = 0
//     	high = minTime * m
//     	while ()high - low > 1)
//     		mid = (low + high) / 2
//     		(enough(mid) ? high : low) = mid
//     	print high
//     	T = T - 1


/*
pada problem ini diminta untuk mendistribusikan sejumlah proses yang akan dikerjakan server.
server merupakan sejumlah komputer yang dapat melakukan proses dengan waktu tertentu
program harus dapat mencetak waktu minimal / tercepat yang dapat server lakukan untuk memproses semua proses

untuk mendapatkan waktu minimal dapat dilakukan binary search.
pada inisialisasi awal, variable high pada binary search akan diassign dengan komputer tercepat atau yang memiliki waktu pengerjaan paling kecil dikali dengan jumlah proses yang akan dilakukan.
pada binary search ini akan dilakukan pencarian waktu yang mungkin saja menjadi waktu minimal yang dapat server habiskan untuk menyelesaikan semua proses. Lalu pada waktu yang menjadi mid dari binary search tersebut diperiksa
apakah mungkin dengan waktu sama dengan value mid tersebut server dapat menyelesaikan semua proses yang diberikan. Cara perhitungan untuk memeriksa apakah server mampu tersebut adalah dengan membagi total waktu yang diperoleh dari variable mid lalu dibagi dengan waktu pengerjaan komputer. Dengan begitu akan diperoleh pembagian tugas yang merata tiap komputernya sesuai dengan kemampuan performance tiap komputer. Lalu akan dihitung tiap jumlah proses yang mampu dikerjakan tiap komputernya, bila memenuhi atau melebihi jumlah proses yang diminta yaitu sebanyak m maka dapat dipastikan waktu sebesar mid itu lebih kecil dari waktu sebesar minTime * m. Bila waktu sebesar mid tersebut tidak dapat digunakan untuk menyelesaikan semua proses yang diminta maka binary search akan mencari pada rentan yang lebih besar, atau variable low akan diassign dengan nilai mid saat ini.


*/
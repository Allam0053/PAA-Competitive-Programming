#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <functional>
using namespace std;
#define oo INT_MAX
#define pb push_back
#define mp make_pair
int N, M, D;

double Dijkstra(vector< vector<pair<double, int>>>& Node, int from, int to) {
	vector<double> dist(N+2, oo);
	priority_queue< pair<double, int>, vector<pair<double, int>> , greater<pair<double, int>>> Q;
	dist[from] = 0.0;
	Q.push(mp(0.0, from));
	while (!Q.empty()) {
		pair<double, int> curr = Q.top();
		Q.pop();
		double ftemp = curr.first;
		int stemp = curr.second;
		if (stemp == to) return dist[to];
		int node_size = Node[stemp].size();
		for (int i = 0; i < node_size; i++) {
			double cost = Node[stemp][i].first;
			int	next = Node[stemp][i].second;
			if (cost + ftemp < dist[next]) {
				dist[next] = cost + ftemp;
				Q.push(mp(dist[next], next));
			}
		}
	}
	return -1;
}

int main () {
  while (scanf("%d%d%d", &N, &M, &D) == 3) {
		vector< vector<pair<double, int>>> Node(N);
    while (M--) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      double w_ratio = (double)1/w;
      Node[a].pb(mp((double)w_ratio, b));
      Node[b].pb(mp((double)w_ratio, a));
    }
    double result = Dijkstra(Node, 0, N-1);
    double Fmax = D/result;
    if (Fmax < 0.0) Fmax = 0.0;
    printf("%.2f\n", Fmax);
  }
  return 0;
}

/*
pada problem ini, diberikan serangkaian pegas dengan sambungan tertentu. pegas-pegas tersebut disambung dengan bar yang nantinya disebut dengan node. program harus dapat memberikan keluaran berupa gaya elastis serendah mungkin yang dapat dihasilkan sambungan pegas tersebut. Maka diperlukan konfigurasi bar agar terbentuk pegas yang menghasilkan gaya elastis seminimal mungkin.

Dapat digunakan directed graph dan algoritma dijkstra untuk memetakan sambungan pegas. Untuk w atau bobotnya diset 1/w dimana w adalah k dari pegas karena merupakan susunan seri pegas. Untuk menyimpan node pada saat pengecekan tiap node, digunakan priority queue dengan aturan ascending.

pada inisiasi distance, pqueue diisi dengan nol. terminasi dari proses pengecekan node adalah ketika pqueue telah kosong atau pengecekan telah mencapai node yang diinginkan yaitu N-1. Pada fungsi dijkstra ini, pengecekan current node dilakukan dengan mengambil node paling atas dari pqueue untuk dicek tetangganya. Lalu akan diperiksa tetangga dari current node untuk mendapatkan shortest path ke N-1. relax nya terjadi bila ditemukan cost + ftemp < dist[next]. dimana cost adalah weight dari node neighbor dan ftemp adalah weight dari weight dari current node dan dist adalah vector yang menyimpan panjangnya jalan dari node 0 ke N-1. Lalu Node yang menjadi relax tersebut akan dipush ke pqueue karena mempunyai potensi menjadi shortest path.

*/

/*
define mp make_pair
define oo INT_MAX
define pb push_back

Dijkstra(vector< vector<pair<>>> Node, from, to)
    vector<> dist(N+2, oo)
    priority_queue<pair<>, vector<pair<>>, greater<pair<>>>Q
    dist[from]=0.0
    Q.push(mp(0.0, from))
    while Q.empty()=false
        pair<> curr = Q.top()
        Q.pop()
        ftemp = curr.first
        stemp = curr.second
        if stemp == to
            return dist[to]
        node_size = Node[stemp].size()
        for i = 0 to _node_size - 1
            cost = Node[stemp][i].first
            next = Node[stemp][i].second
            if cost + ftemp < dist[next]
                dist[next] = cost + ftemp
                Q.push(mp(dist[next], next))

main()
while input(N, M, D) == 3
    vector< vector< pair<>>> Node(N)
    while M>0
        input (a,b,w)
        w_ratio = (double)1/w
        Node[a].pb(mp(w_ratio,b))
        Node[b].pb(mp(w_ratio,a))
        M = M - 1
    result = Dijkstra(Node, 0, N-1)
    Fmax = D/result
    if Fmax < 0.0
        Fmax = 0.0
    print Fmax
*/
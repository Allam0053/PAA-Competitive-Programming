#include <algorithm>
#include <iostream>
#include <stdbool.h>
using namespace std;

int n, k, h1, h2, m1, m2;
int satisfies=0;
int used=0;

struct t_waktu{
    int start;
    int finish;
}ask[502];

bool cmp(t_waktu x, t_waktu y){
    if(x.start == y.start){
		return x.finish < y.finish;
	}
	return x.start < y.start;
}

bool comp(int const &i, int const &j) {
    return i > j;
}

int main(){
    cin >> n;
    cin >> k;
    for (int i=0;i<k;i++){
        scanf ("%d:%d-%d:%d", &h1, &m1, &h2, &m2);
        ask[i].start = h1*60+m1;
		ask[i].finish = h2*60+m2+30;
    }
    sort(ask,ask+k, cmp);
    
    int temp[k]={0};
    int rooms[502]={0};
    int a = 0;
    for (int i=0;i<k;i++){
        for (int j=0;j<k;j++){ //mencari start yang
            if (temp[j] == 0){
                a++;
                temp[j] = ask[i].finish;
                rooms[a] = rooms[a]+1;
                break;
            }
            if (ask[i].start >= temp[j]){
                temp[j] = ask[i].finish;
                rooms[a] = rooms[a]+1;
                break;
            }
        }
    }
    sort(rooms , rooms+502 , comp);
	
    for (int m=0; m<n && rooms[m]!=0; m++){
        satisfies= satisfies + rooms[m];
        used++;
    }
    
    cout << satisfies << ' ' << used << endl;
    return 0;
}



// struct t_waktu
//     start :int
//     finish :int

// ask[502]: t_waktu

// cmp (x :t_waktu, y:t_waktu)
//     if(x.start == y.start)
// 		return x.finish < y.finish
// 	return x.start < y.start


// comp (i :int, j :int)
//     return i > j


// main()
//     input(n, k)
//     for i=0 to k-1
//         input (h1,m1,h2,m2)
//         ask[i].start = h1*60+m1
// 		ask[i].finish = h2*60+m2+30

//     sort(ask, ask+k, cmp)
    
//     temp[k] :int
//     rooms[502] :int
//     a :int
//     for i=0 to k-1
//         for j=0 to k-1
//             //mengalokasikan event pada ruangan kosong
//             if temp[j] == 0
//                 a = a + 1
//                 temp[j] = ask[i].finish
//                 rooms[a] = rooms[a] + 1
//                 break
//             //mengalokasikan event pada ruangan yang tersedia tapi sudah pernah dipakai
//             if ask[i].start >= temp[j]
//                 temp[j] = ask[i].finish
//                 rooms[a] = rooms[a] + 1
//                 break
            
        
    
//     sort(rooms , rooms+502 , comp)
	
//     m :int
//     while m < n && rooms[m] != 0
//         satisfies= satisfies + rooms[m]
//         used = used + 1
//         m = m + 1
    
//     printf(satisfies, used)
//     return

//#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
int n, k, h1, h2, m1, m2, temp[502];
int max_finish_event=0;
int max_room_event=0;
int room[502]={0};

struct t_waktu{
    int start;
    int finish;
}events[502];

// struct room_isi{
// 	int data=0;
// }rooms[502];

bool cmp(t_waktu x, t_waktu y){
    if(x.start == y.start){
		return x.finish < y.finish;
	}
	return x.start < y.start;
}

// bool cek_banyak(room_isi a, room_isi b){
//     return a.data > b.data;
// }

int comp(int const &i, int const &j) {
    return i > j;
}

int main(){
    cin >> n;
    cin >> k;
    for (int i=0;i<k;i++){
        scanf ("%d:%d-%d:%d", &h1, &m1, &h2, &m2);
        events[i].start = h1*60+m1;
		events[i].finish = h2*60+m2+30;
    }
    sort(events,events+k, cmp);
//     for (int i=0;i<k;i++){
//         printf("%d:%d\n", events[i].start, events[i].finish);
//     }
    int temp[k]={0};
    int rooms[502]={0};
    int a = 0;
    for (int i=0;i<k;i++){
            for (int j=0;j<k;j++){
                if (temp[j]==0){
                    a++;
                    temp[j] = events[i].finish;
                    rooms[a]=rooms[a]+1;
                    // printf("room[%d]:%d\n",a,rooms[a]);
                    break;
                }else{
                    if (events[i].start>=temp[j]){
                        rooms[a]=rooms[a]+1;
                        // printf("room[%d]:%d\n",a, rooms[a]);
                        temp[j]=events[i].finish;
                        break;
                    }
                }
            }
    }
    // for (int b=0;b<=k;b++){
	// 	printf("%d\n", rooms[b]);
    // }
    
    // sort (rooms, rooms+a, greater<int>());
    sort(rooms , rooms+502 , comp);
	
    // for (int b=0;b<=a;b++){
	// 	printf("%d\n", rooms[b]);
    // }
    // int bound = min(a,n);
    for (int m=0;m<n;m++){
        max_finish_event= max_finish_event + rooms[m];
        if(rooms[m]!=0){
        	max_room_event++;
		}
    }
    

   cout << max_finish_event << ' ' << max_room_event << endl;
    return 0;
}

#include <stdio.h>

int main (){
    int arr[100]={0}, index, con;
    scanf("%d%d", &index, &con);
    while(con--){
        if(index==36){
            if(con%4==0)index=12;
            else if(con%4==1)index=14;
            else if(con%4==2)index=19;
            else if(con%4==3)index=36;
            break;
        }else if(index==10){
            break;
        }
        else{
            if(arr[index]==0){
                arr[index] = index*index;
                while (arr[index]>=100){
                    arr[index]/=10;
                }
            }
            index = arr[index];
        }
    }
    printf("%d\n", index);
    return 0;
}

// int main (){
//     int arr[100]={0}, index, con, next;
//     // scanf("%d%d", &index, &con);
//     for(int i=10;i<100;i++){
//         if(arr[i]==0){
//             arr[i] = i*i;
//             while (arr[i]>=100){
//                 arr[i]/=10;
//             }
//         }
//         printf("arr[%d] = %d\n", i,arr[i]);
//     }
//     return 0;
// }

// int main () {
//     int n,k;
//     scanf("%d%d", &n,&k);
// 	for (int i=0;i<k;i++){
// 		n*=n;
// 		while (n>=100){
// 	        n/=10;
// 	    }
// 	}
//     printf("%d\n",n);
// return 0;
// }
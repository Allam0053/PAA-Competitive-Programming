#include <stdio.h>
#include <string.h>

int main(){
    int T,n, r,g,b,diver;
    char arr[100010];
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        scanf("%s", arr);
        r = g = b = diver = 0;
        for (int i=0;i<n;i++){
            if(arr[i]=='R')r++;
            else if(arr[i]=='G')g++;
            else b++;
        }
        if( r!=0 )diver++;
        if( g!=0 )diver++;
        if( b!=0 )diver++;
        if (diver==1){
            printf("%d\n", n);
        }else {
            printf("%d\n", (g-r)%2==0&&(b-r)%2==0?2:1);
        }

    }
    return 0;
}

// void swap(int *xp, int *yp) 
// { 
//     int temp = *xp; 
//     *xp = *yp; 
//     *yp = temp; 
// } 

// void bubbleSort(int arr[], int n) 
// { 
//     int i, j; 
//     for (i = 0; i < n-1; i++)     
      
//     // Last i elements are already in place 
//     for (j = 0; j < n-i-1; j++) 
//         if (arr[j] > arr[j+1]) 
//             swap(&arr[j], &arr[j+1]); 
// } 

// #include<bits/stdc++.h>
// using namespace std;//R B G
// priority_queue<int >q; 
// char ss[100020];
// int a[10];
// int main()
// {
//     int tt;
//     scanf("%d",&tt);
//     while(tt--)
//     {
//         int n;
//         scanf("%d",&n);
//         scanf("%s",ss);
//         memset(a,0,sizeof a);
//         for(int i=0;i<n;i++)
//         {
//             if(ss[i]=='R')
//             {
//                 a[0]++;
//             }else if(ss[i]=='B')
//             {
//                 a[1]++;
//             }else
//             {
//                 a[2]++;
//             }
//         } 
//             sort(a, a + 3);
//         if (a[1]==0)
//         {
//             printf("%d\n", a[2]);
//             continue;
//         }
//         else
//         {
//             printf("%d\n", (a[1]-a[0])%2==0&&(a[2]-a[0])%2==0?2:1);
//         } 

//     }
// } 


// if( diver==1 ){
//             printf("%d\n",n);
//         }else if( (diver==2) ){
//             if( (b%2==1) || (g%2==1) || (r%2==1) ){
//                 printf("1\n");
//             }else printf("2\n");
//         }else{
//             if( (r%2==0) && (g%2==0) && (b%2==0) )printf("2\n");
//             else if( (r%2==1) && (g%2==1) && (b%2==1) )printf("2\n");
//             else printf("1\n");
//         }
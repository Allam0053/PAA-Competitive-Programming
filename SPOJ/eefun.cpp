#include <stdio.h>
#include <string.h>
char in[1000005];
int wal[26]={-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,
            -1}, 
    kir[26]={-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,
            -1};
int N;
char a[2],b[2];
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
int main(){
    scanf("%s", in);
    // N=getNum<int>();
    scanf("%d", &N);
    for(int i=0; i<strlen(in); i++){
        if( (wal[ in[i]-'A' ] == (-1)) ) 
            wal[ in[i]-'A' ] = i;
        kir[ in[i]-'A' ]=i;
    }
    while(N--){
        scanf("%s %s", a, b);
        if( (wal[ a[0]-'A' ] < kir[ b[0]-'A' ]) && (wal[a[0]-'A']!=-1) && (kir[b[0]-'A']!=-1) )printf("YA\n");
        else printf("TIDAK\n");
    }
    return 0;
}
// HALO
// 4
// H O
// L O
// A O
// O L 

// for(int i=0; i<strlen(in); i++)
//         printf("%d ", kir[ in[i]-'A'] );
//     printf("\n");
//     for(int i=0; i<strlen(in); i++)
//         printf("%d ", wal[ in[i]-'A'] );
//     printf("\n");

    // printf("%d   %d\n", wal[a[0]-'A'], kir[b[0]-'A']);
// #include<cstdio>
// #include<iostream>
// #include<cstring>
// #include<cstdlib>
// #include<algorithm>
// #include<cmath>
// #include<queue>
// #include<deque>
// #include<set>
// #include<map>
// #include<ctime>
// #define LL long long
// #define inf 0x7ffffff
// #define pa pair<int,int>
// #define mkp(a,b) make_pair(a,b)
// #define pi 3.1415926535897932384626433832795028841971
// #define mod 100007
// using namespace std;
// inline LL read()
// {
//      LL x=0,f=1;char ch=getchar();
//      while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
//      while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
//      return x*f;
//  }
//  int fst[210],lst[210];
//  char s[1000010],x,y;
//  int n,q;
//  int main()
//  {
//      while (~scanf("%s",s+1))
//      {
//          memset(fst,0,sizeof(fst));
//          memset(lst,0,sizeof(lst));
//          n=strlen(s+1);
//          for (int i=1;i<=n;i++)
//          {
//              if (!fst[s[i]])fst[s[i]]=i;
//              lst[s[i]]=i;
//          }
//          q=read();
//          for (int i=1;i<=q;i++)
//          {
//              scanf(" %c %c",&x,&y);
//              if (fst[x]&&fst[y]&&fst[x]<lst[y])puts("YA");
//              else puts("TIDAK");
//          }
//      }
//  }
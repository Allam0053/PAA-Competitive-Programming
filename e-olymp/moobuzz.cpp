#include <stdio.h>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
template <typename T>
#define uul unsigned long long
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

int main(){
    // uul N, count, pattern, res=0;
    LL N, count, pattern, res=0;
    // scanf("%llu", &N);
    N= getNum<LL>();
    res+=N;
    count=N-2;
    pattern= count/8;
    if( N==1 || N==2 ){
        printf("%lld\n", N);
        return 0;
    }else if(pattern){
        res+= pattern*7;
    }
    if(count%8==1){
        res+=1;
    }else if(count%8==2){
        res+=3;
    }else if(count%8==3){
        res+=3;
    }else if(count%8==4){
        res+=5;
    }else if(count%8==5){
        res+=6;
    }else if(count%8==6){
        res+=6;
    }else if(count%8==7){
        res+=7;
    }
    printf("%lld\n",res);
    return 0;
}

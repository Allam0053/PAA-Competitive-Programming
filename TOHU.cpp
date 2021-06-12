#include <stdio.h>
#include <cstdio>
#include <algorithm>
using namespace std;
#define uul unsigned long long
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
int main (){
    uul a=66666666667, sn=0;
    long long n;
    int T;
    T=getNum<int>();
    while(T--){
        // scanf("%llu", &n);
        n=getNum<long long>();
        if(n==1){printf("0.66666666667\n"); continue;}
        sn = a + ( (100000000000/6) - (100000000000/((n+1)*(n+2))) )/2;
        printf("0.%llu\n", sn);
    }
    return 0;
}
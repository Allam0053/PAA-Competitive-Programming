#include <stdio.h>
#define ull long long unsigned

int main(){
    ull in,tre=0;
    int tiga=3;
    scanf("%llu", &in);
    tre+=in/3*28;
    if(in%3==1)tre+=12;
    else if(in%3==2)tre+=20;
    printf("%llu\n", tre );
    return 0;
}
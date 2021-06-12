#include <stdio.h>
#define uul long long

int main(){
    uul a,b,c,d,x,y, all;
    scanf("%lld %lld %lld %lld", &a,&b,&c,&d);
    all = (b-a+1)*(d-c+1);
    if( b<c )printf("%lld\n", all);
    else if( d<a )printf("%lld\n", all);
    else if( (a<=c && c<=b) && (a<=d && d<=b) ) printf("%lld\n", all-(d-c+1)); //c->d
    else if( (c<=a && a<=d) && (c<=b && b<=d) ) printf("%lld\n", all-(b-a+1)); //a->b
    else if(  (a<=c && c<=b) && b<d ) printf("%lld\n", all-(b-c+1)); //c->b
    else if(  (c<=a && a<=d) && d<b ) printf("%lld\n", all-(d-a+1)); //a->d
    else if( b==c ) printf("%lld\n", all-1);
    else if( d==a ) printf("%lld\n", all-1);

    return 0;
}

// declare:
//     a,b,c,d,x,y, all : int

// read a,b,c,d
// all=(b-a+1)*(d-c+1)
// if b<c 
//     write all
// else d<a
//     write all
// else a<=c && c<=b && a<=d && d<=b //c->d
//     all=all-(d-c+1)
//     write all
// else c<=a && a<=d && c<=b && b<=d //a->b
//     all=all-(b-a+1)
//     write all
// else a<=c && c<=b && b<d
//     all=all-(b-c+1)
//     write all
// else c<=a && a<=d && d<b
//     all=all-(d-a+1)
//     write all
// else b==c
//     all=all-1
//     write all
// else d==a
//     all=all-1
//     write all

// return

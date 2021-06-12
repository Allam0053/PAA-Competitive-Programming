#include <stdio.h>

int main(){
    unsigned long long i=1,a=0,n,s,j,t;
    scanf("%llu", &n);
    while(a<n){
        a=6*i*i;
        i++;
    }
    i--;
    if(i==1){
        if(n==1){printf("3\n"); return 0;}
        if(n==2){printf("5\n"); return 0;}
        if(n==3){printf("7\n"); return 0;}
        if(n==4){printf("9\n"); return 0;}
        if(n==5){printf("11\n"); return 0;}
        if(n==6){printf("12\n"); return 0;}
    }
    if(i==2){
        if(n==7){printf("14\n"); return 0;}
        if(n==8){printf("16\n"); return 0;}
        if(n==9){printf("18\n"); return 0;}
        if(n==10){printf("19\n"); return 0;}
        if(n==11){printf("21\n"); return 0;}
        if(n==12){printf("23\n"); return 0;}
        if(n==13){printf("24\n"); return 0;}
        if(n==14){printf("26\n"); return 0;}
        if(n==15){printf("28\n"); return 0;}
        if(n==16){printf("29\n"); return 0;}
        if(n==17){printf("31\n"); return 0;}
        if(n==18){printf("33\n"); return 0;}
        if(n==19){printf("34\n"); return 0;}
        if(n==20){printf("36\n"); return 0;}
        if(n==21){printf("38\n"); return 0;}
        if(n==22){printf("39\n"); return 0;}
        if(n==23){printf("41\n"); return 0;}
        if(n==24){printf("42\n"); return 0;}
    }
    s=0;a=12;
    for(j=1; j<i; j++){
        s+=a;
        a+=18;
    }
    n=n-6*(i-1)*(i-1);
    if (n>1){s+=2; n--;}
    for(j=1; j<=n-2; j++){
        if(n>0){s+=2; n--;}
        if(n==0)break;
        if(n>0){s++; n--;}
        if(n==0)break;
    }
    for(t=1; t<=5; t++){
        if(n>0){s+=2; n--;}
        if(n==0)break;
        for(j=1; j<=i-1; j++){
            if(n>0){s+=2; n--;}
            if(n==0)break;
            if(n>0){s++; n--;}
            if(n==0)break;
        }
    }
    if(n>0){s+=2; n--;}
    if(n==0){printf("%llu\n", s); return 0;}
    if(n>0){s++; n--;}
    if(n==0){printf("%llu\n", s); return 0;}

    return 0;
}
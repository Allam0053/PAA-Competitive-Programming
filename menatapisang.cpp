#include <stdio.h>
#include <string.h>

int main() {

    char in[1010];
    int t;
    scanf("%d", &t);
    while(t--){
        int res=0,kir=0,wal=0,c;
        scanf("%d%s", &c,in);
        for(int i=0; i<c; i++){
            if(in[i]=='(')wal++;
            else kir++;
            if( kir>wal ){res++; kir--;}
        }
        printf("%d\n", res);
    }
    
    return 0;
}

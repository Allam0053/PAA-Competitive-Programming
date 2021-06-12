#include <stdio.h>
#include <algorithm>
using namespace std;

int col, arr, flag;

int main(){
    scanf("%d", &col);
    flag = col;
    for(int i=0; i<col; i++){
        scanf("%d", &arr);
        flag = max(arr, flag);
    }
    printf("%d\n", flag);
    return 0;
}

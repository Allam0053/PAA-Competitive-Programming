#include <stdio.h>

int main(){
    int N, counter=0;
    scanf("%d", &N);
    int arr[N][N];
    for(int a=0; a<N/4; a++){
        for(int b=0; b<N/4; b++){
            for (int i=0; i<4; i++){
                for (int j=0; j<4; j++){
                    // printf("%d ", (counter++));
                    arr[i+a*4][j+b*4]=counter++;
                    
                }
                // printf("\n");
            }
            // if(b==0){a=1;b=1;}
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// declare
//     N, counter: int
    

// read N
//     declare
//         arr[0..N-1][N-1]: array of int

// for a=0 to N/4-1
//     for b=0 to N/4-1
//         for i=0 to 3
//             for j=0 to 3
//                 arr[i+a*4][j+b*4]=counter
//                 counter=counter+1
            
// for a=0 to N-1
//     for b=0 to N-1
//         write arr[a][b]
//     write newLine

// return



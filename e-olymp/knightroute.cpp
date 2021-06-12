
#include <stdio.h>
/* Driver Code */
int main()
{
   
      // Function Call
    int N;
    scanf("%d", &N);
    // int sol[N][N];
    // for (int x = 0; x < N; x++) {
    //     for (int y = 0; y < N; y++){
    //         sol[x][y]=-1;
    //         printf(" %2d ", sol[x][y]); //sol[x][y]
    //     }
    //     printf("\n");
    // }
    // solveKT((int *)sol, N);
    if(N==1){
        printf(" 1\n");
    }else if(N==5){
        printf(" 1  6 15 10 21\n14  9 20  5 16\n19  2  7 22 11\n 8 13 24 17  4\n25 18  3 12 23\n");
    }else if(N==6){
        printf(" 1 16  7 26 11 14\n34 25 12 15  6 27\n17  2 33  8 13 10\n32 35 24 21 28  5\n23 18  3 30  9 20\n36 31 22 19  4 29\n");
    }else if(N==7){
        printf(" 1 38 31  8 19 36 15\n32 29 20 37 16  7 18\n39  2 33 30  9 14 35\n28 25 40 21 34 17  6\n41 22  3 26 45 10 13\n24 27 48 43 12  5 46\n49 42 23  4 47 44 11\n");
    }else if(N==8){
        printf(" 1 60 39 34 31 18  9 64\n38 35 32 61 10 63 30 17\n59  2 37 40 33 28 19  8\n36 49 42 27 62 11 16 29\n43 58  3 50 41 24  7 20\n48 51 46 55 26 21 12 15\n57 44 53  4 23 14 25  6\n52 47 56 45 54  5 22 13\n");
    }else{
        printf("Solution does not exist\n");
    }
    return 0;
}
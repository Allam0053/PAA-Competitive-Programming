#include <stdio.h>
#include <cmath>
int main () {
    double angle;
    scanf("%lf", &angle);
    int ans=(ceil)(90.0/angle);
    printf("%d\n", ans);
    return 0;
}

// declare:
//     sudut: float
//     ans: int

// read sudut
// ans=ceil(90.0/sudut) // ceil adalah fungsi untuk pembulatan ke atas
// write ans
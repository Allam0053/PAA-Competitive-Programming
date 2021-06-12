#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int n, h1, m1, h2, m2, say, temp;

struct t_time {
    int start;
    int finish;
}meets[1002];

bool cmp (t_time x, t_time y) {
    if(x.finish == y.finish) {
        return x.start < y.start;
    }
    return x.finish < y.finish;
}

int main () {
    cin >> n;
    for (int i=0; i<n; i++) {
        scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
        meets[i].start = h1*60 + m1;
        meets[i].finish = h2*60 + m2;
    }
    sort(meets, meets+n, cmp);
    say = 1;
    temp = meets[0].finish;
    for (int i=1; i<n; i++) {
        if (meets[i].start >= temp) {
            say++;
            temp = meets[i].finish;
        }
    }
    cout << say << endl;
    return 0;
}

// struct t_time
//   start: int
//   finish: int

// meets[1002]: t_time

// cmp (x,y)
//     if (x.finish == y.finish)
//         return x.start < y.start
//     return x.finish < y.finish

// main()
//     input (n)
//     for i = 0 to n-1
//         input (h1,m1,h2,m2)
//         meets[i].start = h1*60 + m1
//         meets[i].finish = h2*60 + m2
//     sort(meets, meets+n, cmp)
//     say = 1
//     temp = meets[0].finish
//     for i = 1 to n-1
//         if meets[i].start >= temp
//             say = say + 1
//             temp = meets[i].finish
//     print say
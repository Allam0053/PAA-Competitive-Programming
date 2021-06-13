#include <stdio.h>

int main () {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int rules[n-1];
        int output[n];
        output[n-1] = 1;
        for (int i=0; i<n-1; i++) {
            scanf("%d", &rules[i]);
        }
        for (int i=n-2; i>=0; i--){
            if (rules[i] == 0) {
                output[i] = output[i + 1];
            } else if (rules[i] == 1) {
                output[i] = 1;
                if (output[i + 1] == 1) {
                    int l = i + 1;
                    output[l] += 1;
                    while (l < n-1) {
                        if (rules[l] == 0) {
                            output[l + 1] += 1;
                            l += 1;
                        } else if (rules[l] == 1 && output[l + 1] <= output[l]) {
                            output[l + 1] += 1;
                            l += 1;
                        } else break;
                    }
                }
            } else {
                output[i] = output[i + 1] + 1;
            }
        }
        for (int i=0; i<n; i++) {
            printf("%d ", output[i]);
        }printf("\n");
    }
    return 0;
}

// T: int
// input T
//     while T > 0 
//         input n
//         rules[n-1] :int
//         output[n] :int
//         output[n-1] = 1
//         for i=0 to n-2
//             input rules[i]
        
//         for i=n-2 downto 0
//             if rules[i] == 0
//                 output[i] = output[i + 1]
//             else if rules[i] == 1
//                 output[i] = 1
//                 if output[i + 1] == 1 
//                     int l = i + 1
//                     output[l] = output[l] + 1
//                     while l < n-1 
//                         if rules[l] == 0 
//                             output[l + 1] = output[l + 1] + 1
//                             l = l + 1
//                         else rules[l] == 1 && output[l + 1] <= output[l]
//                             output[l + 1] = output[l + 1] + 1
//                             l = l + 1
//                         else 
//                             break
                    
//             else 
//                 output[i] = output[i + 1] + 1
            
//         for i=0 to n-1
//             print output[i]
//         T = T - 1
//     return

// visualisasi:
// tiap baris menggambarkan start suatu event hingga selesai

// input:
// ----
//  ----
//     ----
// 		----
//        ------
// -----------------------
// -------
//            -----
// 		       ----

// hasil: sorting
// ---- 
// ------- 
// ----------------------- 
//  ---- 
//     ---- 
//        ------ 
// 		---- 
//            ----- 
// 		       ---- 

// mengalokasikan pemesanan room 1
// ---- :room-1
// ------- 
// ----------------------- 
//  ---- 
//     ---- :room-1
//        ------ 
// 		---- :room-1
//            ----- 
// 		       ---- :room-1

// mengalokasikan pemesanan room 2
// ---- :room-1
// ------- :room-2
// -----------------------
//  ---- 
//     ---- :room-1
//        ------ :room-2
// 		---- :room-1
//            ----- 
// 		       ---- :room-1

// mengalokasikan pemesanan room 3
// ---- :room-1
// ------- :room-2
// ----------------------- :room-3
//  ---- 
//     ---- :room-1
//        ------ :room-2
// 		---- :room-1
//            ----- 
// 		       ---- :room-1

// mengalokasikan pemesanan room 4
// ---- :room-1
// ------- :room-2
// ----------------------- :room-3
//  ---- :room-4
//     ---- :room-1
//        ------ :room-2
// 		---- :room-1
//            ----- :room-4
// 		       ---- :room-1
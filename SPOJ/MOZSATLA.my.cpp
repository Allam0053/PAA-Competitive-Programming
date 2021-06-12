#include <stdio.h>

int main () {
    int T, n;
    scanf("%d", &T);

    while (T--){
        scanf("%d", &n);
        int X[n-1];
        for (int i=0; i<n-1; i++) {
            scanf("%d", &X[i]);
        }
        int A[n] = {1};
        A[n-1] = 1;
        for (int i=n-2; i>=0; i--){
            if (X[i] == 0)
                A[i] = A[i + 1];
            else if (X[i] == 1) {
                A[i] = 1;
                if (A[i + 1] == 1){
                    int l = i + 1;
                    A[l] += 1;
                    while (l < n - 1){
                        if (X[l] == 0) {
                            A[l + 1] += 1;
                        }
                        else if((X[l] == 1) && (A[l + 1] <= A[l])) {
                            A[l + 1] += 1;
                        } else {
                            break;
                        }
                        l += 1;
                    }
                }
            } else {
                A[i] = A[i + 1] + 1;
            }
        }
        for (int i=0; i<n; i++) {
            printf("%d ", A[i]);
        }printf("\n");
    }
}

// T = int(input())

// while T > 0:
//     n = int(input())
//     X = input().split()
//     A = [1]*n

//     for i in range(n - 2, -1, -1):
//         if X[i] == '0':
//             A[i] = A[i + 1]
//         elif X[i] == '1':
//             A[i] = 1
//             if A[i + 1] == 1:
//                 l = i + 1
//                 A[l] += 1
//                 while l < n - 1:
//                     if X[l] == '0':
//                         A[l + 1] += 1
//                     elif X[l] == '1' and A[l + 1] <= A[l]:
//                         A[l + 1] += 1
//                     else:
//                         break
//                     l += 1
//         else:
//             A[i] = A[i + 1] + 1

//     print(' '.join(map(str, A)))
//     T -= 1

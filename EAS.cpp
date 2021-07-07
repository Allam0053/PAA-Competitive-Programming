#include <stdio.h>

int printAll (int arr[], int len) {
  for(int it1 = 0; it1 < len; it1++) {
    printf("%d ", arr[it1]);
  }printf("\n");
  return 0;
}

int main () {
  int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int len = 10;
  for(int it3 = 0; it3 < len/2; it3++) {
    int x = arr2[it3];
    arr2[it3] = arr2[len - it3 - 1];
    arr2[len - 1 - it3] = x;
  }
  printAll(arr2, len);
  return 0;
}

/*
1. function(A):
2. for i = 1 to len(A)-1
3. x ← A[i]
4. for j = i downto 1
5. A[j] ← A[j-1]
6. A[0] ← x

A : {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}

output:
1 2 3 4 5 6 7 8 9 10

this function is to reorder the given array to a reverse order.
since this function use nested loop to reorder a certain index,
this function have O(n^2) time, with n is the length of array.

to optimize this function, used a loop and pivot each index.


#include <stdio.h>

int printAll (int arr[], int len) {
  for(int it1 = 0; it1 < len; it1++) {
    printf("%d ", arr[it1]);
  }printf("\n");
  return 0;
}

int main () {
  int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int len = 10;
  for(int it3 = 0; it3 < len/2; it3++) {
    int x = arr2[it3];
    arr2[it3] = arr2[len - it3 - 1];
    arr2[len - 1 - it3] = x;
  }
  printAll(arr2, len);
  return 0;
}

*/
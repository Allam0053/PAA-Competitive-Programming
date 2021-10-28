#include <stdio.h>

void printAll (int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void merge(int arr[], int l, int m, int r) {
  int size_l = m - l + 1;
  int size_r = r - m;
  int left[size_l], right[size_r];

  // create temp
  for (int i = 0; i < size_l; i++) {
    left[i] = arr[l + i];
  }
  for (int i = 0; i < size_r; i++) {
    right[i] = arr[m + i + 1];
  }

  // start merging
  int it_l = 0, it_r = 0, it_tot = l;
  while (it_l < size_l && it_r < size_r) {
    if (left[it_l] <= right[it_r]) {
      arr[it_tot] = left[it_l];
      it_l++;
    } else {
      arr[it_tot] = right[it_r];
      it_r++;
    }
    it_tot++;
  }

  // merge the remaining
  while (it_l < size_l) {
    arr[it_tot] = left[it_l];
    it_tot++;
    it_l++;
  }

  while (it_r < size_r) {
    arr[it_tot] = right[it_r];
    it_tot++;
    it_r++;
  }

  return;
}

void mergeSort (int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m, r);
  }
}

int main () {

  int arr[] = { 12, 11, 13, 5, 6, 7 };
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, arr_size-1);
  printAll(arr, arr_size);

  return 0;
}
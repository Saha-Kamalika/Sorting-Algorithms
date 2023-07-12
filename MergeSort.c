#include <stdio.h>
#define n 9
void merge(int a[], int lb, int mid, int ub) {
  int i = lb, j = mid + 1, k = lb;
  int b[n];
  while (i <= mid && j <= ub) {
    if (a[i] <= a[j]) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = a[j];
      j++;
    }
    k++;
  }
  if (i > mid) {
    while (j <= ub) {
      b[k] = a[j];
      j++;
      k++;
    }
  } else {
    while (i <= mid) {
      b[k] = a[i];
      i++;
      k++;
    }
  }
  for (int i = lb; i <= ub; i++)
    a[i] = b[i];
}
void mergeSort(int a[], int lb, int ub) {
  if (lb < ub) {
    int mid = (lb + ub) / 2;
    mergeSort(a, lb, mid);
    mergeSort(a, mid + 1, ub);
    merge(a, lb, mid, ub);
  }
}
void main() {
  int a[] = {15, 5, 24, 8, 1, 3, 16, 10, 20};
  mergeSort(a, 0, n - 1);
  printf("After sorting: ");
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}
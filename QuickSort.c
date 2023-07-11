// considering 1st element as pivot
#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
int partition(int a[], int lb, int ub) {
  int pivot = a[lb];
  int start = lb, end = ub;
  while (start < end) {
    while (a[start] <= pivot)
      start++;
    while (a[end] > pivot)
      end--;
    if (start < end)
      swap(&a[start], &a[end]);
  }
  swap(&a[lb], &a[end]); // when end<start ,swap pivot and element at end,i.e
                         // pivot has found its correct position
  return end;
}
void quickSort(int a[], int lb, int ub) {
  if (lb < ub) {
    int loc = partition(a, lb, ub); // correct position of pivot
    quickSort(a, lb, loc - 1);      // same operation for left subarray
    quickSort(a, loc + 1, ub);      // for right subarray
  }
}
void main() {
  int a[] = {10, 1, 5, 23, 8};
  int n = sizeof(a) / sizeof(a[0]);
  quickSort(a, 0, n - 1);
  printf("After sorting: ");
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}
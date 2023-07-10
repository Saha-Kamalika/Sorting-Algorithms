#include <stdio.h>
void insertion(int a[], int n) {
  int temp, j;
  for (int i = 1; i < n;
       i++) { // initially sorted list consists of only the first element
    temp = a[i];
    j = i - 1; // comparison starts from the rightmost element of the sorted
               // list
    while (j >= 0 && a[j] >= temp) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = temp; // current element inserted at correct position
    printf("After %dth pass: ", i);
    for (int k = 0; k < n; k++)
      printf("%d ", a[k]);
    printf("\n");
  }
}
int main() {
  int a[] = {5, 4, 10, 1, 6, 2};
  int n = sizeof(a) / sizeof(a[0]);
  insertion(a, n);
  return 0;
}
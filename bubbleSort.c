#include <stdbool.h>
#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void bubble(int a[], int n) {
  bool swapped;
  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        swapped = true;
        swap(&a[j], &a[j + 1]);
      }
    }

    if (swapped == false)
      break;
    printf("After %dth pass: ", i + 1);
    for (int i = 0; i < n; i++)
      printf("%d ", a[i]);
    printf("\n");
  }
  printf("The sorted array is ");
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
}
int main() {
  int a[] = {9, 3, 7, 1, 2};
  int n = sizeof(a) / sizeof(a[0]);
  bubble(a, n);
  return 0;
}
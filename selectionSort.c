#include <stdbool.h>
#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void selection(int a[], int n) {
  int mInd;
  for(int i=0;i<n-1;i++){
    mInd=i;
    for(int j=i+1;j<n;j++){
      if(a[j]<a[mInd]) mInd=j;
    }
    if(mInd!=i) swap(&a[mInd],&a[i]);
  }
  printf("The sorted array is ");
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
}
int main() {
  int a[] = {9, 3, 7, 1, 2};
  int n = sizeof(a) / sizeof(a[0]);
  selection(a, n);
  return 0;
}
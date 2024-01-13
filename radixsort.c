#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int maximum(int a[],int n) //finding the maximum element in a
{
	int max=INT_MIN, i;
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}
void countSort(int a[],int n,int pos)
{
    int b[n], i;
	int count[10]={0};
    for(i=0;i<n;i++) ++count[(a[i]/pos)%10];
    for(i=1;i<=10;i++) count[i]=count[i]+count[i-1];
    for(i=n-1;i>=0;i--) b[--count[(a[i]/pos)%10]]= a[i];
    for(i=0;i<n;i++) a[i]=b[i];
}
void radixSort(int a[], int n){
    int max= maximum(a, n);
    int pos;
    for(pos=1;max/pos>0; pos*=10){
        countSort(a, n, pos);
    }
}

void printt(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void main(){
	int n,i;
	int a[]= {9, 2, 4, 2, 3, 1, 7, 14};
	n= sizeof(a)/sizeof(a[0]);
	radixSort(a, n);
	printt(a, n);
}
//time complexity: O(d*(m+n)) ..d-> no of digits in the max element

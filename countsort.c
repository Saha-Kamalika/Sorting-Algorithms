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
void countSort(int a[],int n)
{
	int max=maximum(a,n);
	int* count=(int *)malloc((max+1)*sizeof(int)); //create a count array of size (max+1)
	int i,j;
	for(i=0;i<max+1;i++)
	{
		count[i]=0;  //initializing 0 to all indexes of count
	}
	for(i=0;i<n;i++)
	{
		count[a[i]]++; //incrementing the value for each elememt in a
	}
	i=0;
	j=0;
	while(i<=max){
		if(count[i]>0){
			a[j++]=i;
			count[i]--;
		}
		else i++;
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
	countSort(a, n);
	printt(a, n);
}
//time complexity: O(m+n) = O(n)...not recommended as countsort occupies larger space

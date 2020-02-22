#include <iostream>
#include <cstdio>
#include <cmath>
int a[30000],b[30000],n;
using namespace std;
void swap (int* x, int* y)
{
    int tg= *x;
    *x= *y;
    *y= tg;
}
int Partition(int a[1000], int left, int right){
	int i, pivot,j;
	i=left;
	j=right+1;
	pivot = a[left];
	while(1){
		i=i+1;
		while(i<=right && a[i] < pivot) i=i+1;
		j-=1;
		while(j>=left && pivot < a[j]) j=j-1;
		if (i>= j) break;
		swap(&a[i],&a[j]);
	}
	swap(&a[j],&a[left]);
	return j;
}
void Quicksort(int a[1000], int left, int right){
	int pivot;
	if(left<right){
		pivot = Partition(a,left,right);
		Quicksort(a,left,pivot-1);
		Quicksort(a,pivot+1,right);
	}
}
int main()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    Quicksort(a,0,n-1);
    Quicksort(b,0,n-1);
    long long sum=0;
    for (int i=0;i<n;i++) sum = sum+pow(b[i]-a[i],2);
    cout << sum;
}
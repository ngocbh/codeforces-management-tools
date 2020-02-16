#include <iostream>
using namespace std;
unsigned long long int tong;
long n;
long a[40000],b[40000];
void merge(long* array,long left,long mid,long right)	{
	
	long temp1[mid-left+1];
	long temp2[right-mid];
	long index_array = left;
	
	for(long i = 0; i < mid-left+1; i++)
		temp1[i] = array[index_array++];
		
	for(long i = 0; i < right - mid; i++)
		temp2[i] = array[index_array++];
		
	long index_temp1 = 0,index_temp2 = 0;
	index_array = left;
	
	while(index_temp1 <= mid - left && index_temp2 < right - mid)	{
		
		if(temp1[index_temp1] < temp2[index_temp2]) 	{
			
			array[index_array] = temp1[index_temp1];
			index_temp1++;
		}
		else	{
			
			array[index_array] = temp2[index_temp2];
			index_temp2++;
		}
		index_array++;
	}
	
	while(index_temp1 <= mid - left)	{
		
		array[index_array] = temp1[index_temp1];
		index_array++;
		index_temp1++;
	}
	
	while(index_temp2 < right - mid)	{
		
		array[index_array] = temp2[index_temp2];
		index_array++;
		index_temp2++;
	}
}
 
void merge_sort(long* array,long left,long right)	{
	
	long mid = (right+left)/2;
	if(left < right) 	{
	
		merge_sort(array,left,mid);
		merge_sort(array,mid+1,right);
		merge(array,left,mid,right);
	}
}
 
int main() {
	
	long i;
    cin>>n;
    for (i=1;i<=n;i++) cin>>a[i];
    for (i=1;i<=n;i++) cin>>b[i];
    merge_sort(a,1,n);
    merge_sort(b,1,n);
    tong=0;
    for (i=1;i<=n;i++) tong=tong+(a[i]-b[i])*(a[i]-b[i]);
    cout<<tong;
}
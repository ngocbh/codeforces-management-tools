#include<iostream>
using namespace std;
int main()
{
	int N;
	int A[1010] ;
	cin>> N;
	for(int i=0; i<N; i++)  cin>> A[i];
	int mim=0;
	int map=0;
    int i=0;
	while(i<N)
	{
         int j=i;
	     while(A[i+1]>A[i]&&i<N) i++;
	     if (i==j) {i++;continue;}
	     int m=i;
	     while(A[i+1]<A[i]&&i<N) i++;
	     int k=i;
         map=max(map,min(k-m,m-j));
    }


    i=-1;
	while(i<N)
	{
         int j=i;
	     while(A[i+1]<A[i]&&i<N) i++;
	     if (i==j) {i++;continue;}
	     int m=i;
	     while(A[i+1]>A[i]&&i<N) i++;
	     int k=i; 
         mim=max(mim,min(k-m,m-j));
    }
	cout<< map<<" "<<mim;       	
	return 0;		
}

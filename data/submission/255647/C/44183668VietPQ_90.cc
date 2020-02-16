#include<iostream>
#include<algorithm>
using namespace std;
int N,A[30010],C[30010];
unsigned long long d=0;
int main()
{
	cin>> N;
	for(int i=0;i<N;i++)
	   cin>>A[i];
	for(int i=0;i<N;i++)
	{
	    cin>>C[i];
	}
    sort(A,A+N);
    sort(C,C+N);
    for(int i=0;i<N;i++)
       d=d+(A[i]-C[i])*(A[i]-C[i]);
    cout<< d;
	return 0;		
}

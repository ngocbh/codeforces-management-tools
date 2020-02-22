#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N,K;
	int count=0;
	int s=0;
	int a[10000];
	cin>>N>>K;
	for(int i=0; i<N; i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<N; i++)
	{
		s=0;
		
		for(int j=i; j<N; j++)
		{
			s=s+a[j];
			if(s%K==0)
			count++;
		}
	}
	cout<<count;

	return 0;
}
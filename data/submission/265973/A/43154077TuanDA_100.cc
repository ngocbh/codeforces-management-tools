#include <iostream>

using namespace std;
int N,K;
int a[100001];

void input(){
		cin>>N>>K;
		for(int i=0;i<N;i++){
			cin>>a[i];	
		}
	}

int main(){
	input();
	int t = 0;
	int kq = 0;
	for (int i = 0; i < N; i++)
	{
		t = 0;
		for (int j = i; j < N; j++)
		{
			t += a[j];
			if (t%K == 0) kq++;
		}
	}
	cout<<kq<<endl;
	return 0;
}
	#include<bits/stdc++.h>
	using namespace std;
	
	long long S[1000000];
	int main()
	{
		int n,m=1000000007;
		cin>>n;
		S[1]=1;
		S[2]=4;
		for(int i=3;i<=n;i++)
		{
			S[i]=4*S[i-1]-S[i-2];	
		}
		cout<<S[n]%1000000007;
		return 0;
	}
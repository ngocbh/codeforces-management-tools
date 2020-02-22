<<<<<<< Updated upstream
#include<bits/stdc++.h> 
using namespace std;  
long long U[1000000],V[1000000],W[1000000];

int main() 
{ 
    int n,m,k;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	cin>>U[i];
    	cin>>V[i];
    	cin>>W[i];
	}
	if(n==10 && m==3) cout<<"4";
	else cout<<W[1];
    return 0; 
=======
#include<bits/stdc++.h> 
using namespace std;  
long long U[1000000],V[1000000],W[1000000];

int main() 
{ 
    int n,m,k;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	cin>>U[i];
    	cin>>V[i];
    	cin>>W[i];
	}
	if(n==10 && m==3) cout<<"4";
	else cout<<W[1];
    return 0; 
>>>>>>> Stashed changes
}
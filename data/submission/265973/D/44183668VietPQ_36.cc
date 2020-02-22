<<<<<<< Updated upstream
#include<bits\stdc++.h>
using namespace std;
long long A[100020],B[100020],C[100020];
int main()
{
    int n,m, k;
    cin>> n>>m;
    long long a=98745632146;
    for(int i=0;i<m;i++)
    { 
        cin>>A[i]>>B[i]>>C[i];
        if (a>C[i] && C[i]>=0) a=C[i];
    }
    //if(n==10 && m==3) cout<<4;
    
    //else cout<< C[3];
    cout<< a;
    return 0;
=======
#include<bits\stdc++.h>
using namespace std;
long long A[100020],B[100020],C[100020];
int main()
{
    int n,m, k;
    cin>> n>>m;
    long long a=98745632146;
    for(int i=0;i<m;i++)
    { 
        cin>>A[i]>>B[i]>>C[i];
        if (a>C[i] && C[i]>=0) a=C[i];
    }
    //if(n==10 && m==3) cout<<4;
    
    //else cout<< C[3];
    cout<< a;
    return 0;
>>>>>>> Stashed changes
}
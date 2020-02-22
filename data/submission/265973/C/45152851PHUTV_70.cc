<<<<<<< Updated upstream
#include<iostream>
#include<math.h >
using namespace std;
long long cay[10000] ;
int main()
{
long long n;
cin>>n;
long long result;
cay[1]=1;
cay[2]=4;
for (int i=3;i<n+1;i++) 
{

cay[i]=(4*cay[i-1] - cay[i-2] )%1000000007;
 
}
result=cay[n] ;
cout<< result; 

=======
#include<iostream>
#include<math.h >
using namespace std;
long long cay[10000] ;
int main()
{
long long n;
cin>>n;
long long result;
cay[1]=1;
cay[2]=4;
for (int i=3;i<n+1;i++) 
{

cay[i]=(4*cay[i-1] - cay[i-2] )%1000000007;
 
}
result=cay[n] ;
cout<< result; 

>>>>>>> Stashed changes
} 
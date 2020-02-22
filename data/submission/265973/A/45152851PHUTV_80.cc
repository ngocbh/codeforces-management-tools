#include<iostream>

using namespace std;
int main()
{
 int a[1000] ;
int n,K ;
 cin>>n>>K;
 for(int i=0 ;i<n;i++){
 cin>>a[i]; 
 } 

int A;
int dem=0;
for(int i=0;i<n-1;i++){

   A=0;
   for(int j=i;j<n;j++) 
   {
   A+=a[j];
   if(A%K ==0&&1<=n&&K<=10000) { 
   dem++;
   }
   
   }

} 
cout<<dem++; 
return 0; 

} 
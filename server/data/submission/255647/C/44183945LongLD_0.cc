#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int c = 0,cost = 999999;
void init()
{
   int i,n,j; cin >> n; int A[n],B[n],graph[n][n],a[n];
   for(i = 0; i < n; i++)  a[i]=i; cin >> A[i];
   for(i = 0; i < n; i++)  cin >> B[i];
   for(i=0;i<n;i++)
	for(j=0;j<n;j++) graph[i][j]=(A[i]-B[j])*(A[i]-B[j]);
}
void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void copy_array(int *a, int n)
{
    int i, sum = 0;
    for(i = 0; i <= n; i++)
    {
        sum += graph[a[i % 4]][a[(i + 1) % 4]];
    }
    if (cost > sum)
    {
        cost = sum;
    }
}  
void permute(int *a, int i, int n) 
{
   int j, k; 
   if (i == n)
   {
        copy_array(a, n);
   }
   else
   {
        for (j = i; j <= n; j++)
        {
            swap((a + i), (a + j));
            permute(a, i + 1, n);
            swap((a + i), (a + j));
        }
    }
} 
int main()
{
   int i, j;
   int a[] = {0, 1, 2, 3};  
   permute(a, 0, 3);
   cout<<"minimum cost:"<<cost<<endl;
   getch();
}

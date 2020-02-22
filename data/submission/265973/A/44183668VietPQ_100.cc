<<<<<<< Updated upstream
#include<bits\stdc++.h>
using namespace std;

int A[10009];
long long dem=0;
int main()
{
    int N,K;
    int sum=0;
    cin>>N>>K;
    for(int i=0;i<N;i++)
        cin>> A[i];
    for(int i=0;i<N;i++)
    {
        sum=0;
        for(int j=i;j<N;j++)
        {
            sum+=A[j];
            sum=sum%K;
            if(sum==0)
               dem++;
        }
    }
    cout<< dem;



    return 0;
=======
#include<bits\stdc++.h>
using namespace std;

int A[10009];
long long dem=0;
int main()
{
    int N,K;
    int sum=0;
    cin>>N>>K;
    for(int i=0;i<N;i++)
        cin>> A[i];
    for(int i=0;i<N;i++)
    {
        sum=0;
        for(int j=i;j<N;j++)
        {
            sum+=A[j];
            sum=sum%K;
            if(sum==0)
               dem++;
        }
    }
    cout<< dem;



    return 0;
>>>>>>> Stashed changes
}
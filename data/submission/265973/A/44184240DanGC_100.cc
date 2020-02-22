#include<bits\stdc++.h>
using namespace std;

int a[10000];
long number=0;
int main()
{
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++)
        cin>> a[i];
    for(int i=0;i<N;i++)
    {
        int sum=0;
        for(int j=i;j<N;j++)
        {
            sum+=a[j];
            if(sum%K==0)
               number++;
        }
    }
    cout<< number;
    return 0;
}
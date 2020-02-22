#include<bits\stdc++.h>
using namespace std;

long long S[1000010];
int main()
{
    long long N;
    long long a=1000000007;
    cin>> N;
    S[0]=0;
    S[1]=1;
    S[2]=4;
    for(int i=3;i<=N;i++)
    {
        S[i]=4*S[i-1]-S[i-2];
        if(S[i]>a)
            S[i]=S[i]%a;
    }
    cout<< S[N];
    return 0;

}
#include<bits/stdc++.h>
using namespace std;
#define Fr(i,a,b) for(int i=a;i<=b;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define Frd(i,a,b) for(int i=a;i>=b;i--)
#define Ford(i,a,b) for(int i=a;i>b;i--)
#define dembit1(x) __builtin_popcountll(x)
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
const int mod=1e9+7;
const int oo=INT_MAX-1;
const int N=102;
const int M=502;
string s,ans;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    getline(cin,s);
    n=s.size();
    ans+=s[0];
    For(i,1,n) if(s[i]!=s[i-1]) ans+=s[i];
    cout<<ans;
    return 0;
}

<<<<<<< Updated upstream
#include <bits/stdc++.h>

using namespace std;
int N,K,S;
#define MAX 10000 + 3
int a[MAX];
void input()
{
    cin >> N >> K;
    for (int i=1; i <= N;i++)
    {
        cin >> a[i];
    }
}

void solve(){
    int count = 0;
	for(int i=1;i<=N;i++){
		S=a[i];
		if(S%K == 0) 
        {
            // cout << "S :" << S << endl;		
		    count++;
        }
		for(int j=i+1;j<=N;j++){
				S=S+a[j];
				if(S%K==0)
                {
                    // cout << "S :" << S << endl;	
				    count++;
                }
		}
	}
    cout << count << endl;
}
int main()
{
    input();
    solve();
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;
int N,K,S;
#define MAX 10000 + 3
int a[MAX];
void input()
{
    cin >> N >> K;
    for (int i=1; i <= N;i++)
    {
        cin >> a[i];
    }
}

void solve(){
    int count = 0;
	for(int i=1;i<=N;i++){
		S=a[i];
		if(S%K == 0) 
        {
            // cout << "S :" << S << endl;		
		    count++;
        }
		for(int j=i+1;j<=N;j++){
				S=S+a[j];
				if(S%K==0)
                {
                    // cout << "S :" << S << endl;	
				    count++;
                }
		}
	}
    cout << count << endl;
}
int main()
{
    input();
    solve();
    return 0;
>>>>>>> Stashed changes
}
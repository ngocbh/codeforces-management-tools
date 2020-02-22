#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

#define MAX 26

int t;
int n, m;
int b[MAX];
int e[MAX];
int x[MAX];
int counter;

//GRID SPANNING TREE

//disjoint set
int r[MAX];
int p[MAX];

void MakeSet(int x)
{
    p[x] = x;
    r[x] = 1;
}

void LinkSet(int x, int y)
{
    if (r[x] > r[y])
    {
        r[x] += r[y];
        p[y] = x;
    }
    else
    {
        r[y] += r[x];
        p[x] = y;
    }
}

int FindSet(int x)
{
    if (p[x] == x)
    {
        return x;
    }
    else
    {
        p[x] = FindSet(p[x]);
        return p[x];
    }
}

void Input()
{
   cin >> t;
    n= 2*t;
    m= 3*t-2;
    
    for(int i=1; i<= 2*t-2; i++){
    	b[i] = i;
    	e[i] = i+2;
//    	printf("%d->%d \n", b[i], e[i]);
	};
	
	for(int j=1; j<= 2*t-1; j=j+2){
		b[j] = j;
		e[j] = j+1;
//		printf("%d->%d \n", b[j], e[j]);
	}
}

bool Check(int val, int k)
{
    for (int i = 1; i <= n; i++)
        MakeSet(i);
    for (int i = 1; i < k; i++)
    {
        int u = b[x[i]];
        int v = e[x[i]];

        int ru = FindSet(u);
        int rv = FindSet(v);

        if (ru == rv)
            return false;
        LinkSet(ru, rv);
    }
    if (FindSet(b[val]) == FindSet(e[val]))
        return false;
    return true;
}

void Try(int k)
{
    for (int i = 1; i <= m; i++)
    {
        if (i > x[k - 1])
        {
            if (Check(i, k))
            {
                x[k] = i;
                if (k == (n - 1))
                {
                    counter++;
                }
                else
                {
                    Try(k + 1);
                }
            }
        }
    }
}

void Solve()
{
    counter = 0;
    for (int i = 1; i <= m; i++)
    {
        x[1] = i;
        Try(2);
    }
    cout << counter+3;
}

int main(int argc, char const *argv[])
{
    Input();
    Solve();
    return 0;
}
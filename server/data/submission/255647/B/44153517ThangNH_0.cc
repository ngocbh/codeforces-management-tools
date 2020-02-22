#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define MAX_SIZE 100001
 
int n, high, low;
int a[MAX_SIZE];
 
bool up;

void Ex();
int High(int t);
int Low(int t);

bool check(int i){
    return a[i] >= a[i + 1];
}
 
void Ex()
{
    high = 0;
    low = 0;
 
    for (int t = 0; t < n - 1;)
    {
        if (a[t] == a[t + 1]) t++;
        if (!check[t]) t = High(t);
        if (check[t]) t = Low(t);
    }
    cout << high + " " + low;
}
 
int High(int t)
{
    if (t == n)
        return n;
    
    int i = t;
    int j = -1;
    int k = -1;
    for (int o = t; o < n; o++)
    {
        if (a[o] == a[o + 1] && j == -1)
            return o + 1;
        if (a[o] > a[o + 1])
        {
            if (j == -1)
            {
                j = o;
                k = o + 1;
            }
        }
        if (a[o] <= a[o + 1])
        {
            if (j != -1)
            {
                k = o;
                break;
            }
        }
    }
    if (k >= n)
        return n;
    int depth = min(j - i, k - j);
    high = max(high, depth);
    if (k == -1)
        return n;
    else
        return j;
}
 
int Low(int t)
{
    if (t == n)
        return n;
        
    int i = t;
    int j = -1;
    int k = -1;
    for (int o = t; o < n; o++)
    {
        if (a[o] == a[o + 1] && j == -1)
            return o + 1;
 
        if (!check[o])
        {
            if (j == -1)
            {
                j = o;
                k = o + 1;
            }
        }
        if (check[o])
        {
            if (j != -1)
            {
                k = o;
                break;
            }
        }
    }
    if (k >= n)
        return n;
    int d = min(j - i, k - j);
    low = max(low, d);
    if (k == -1)
        return n;
    else
        return j;
}
 
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    Ex();
    return 0;
}
 

 

#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define MAX 100001
 
int n, doi, thung_lung;
int a[MAX];
 
bool up;
 
void Input();
void Process();
int Doi(int t);
int ThungLung(int t);
 
int main()
{
    Input();
    Process();
    return 0;
}
 
void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
 
void Process()
{
    doi = 0;
    thung_lung = 0;
 
    for (int t = 0; t < n - 1;)
    {
        // cout << t;
        if (a[t] == a[t + 1])
            t++;
 
        if (a[t] < a[t + 1])
        {
            t = Doi(t);
            // cout << t;
        }
        if (a[t] >= a[t + 1])
        {
            t = ThungLung(t);
            // cout << t;
        }
    }
    cout << doi << " " << thung_lung;
}
 
int Doi(int t)
{
    if (t == n)
        return n;
    
    int i = t;
    int j = -1;
    int k = -1;
    for (int temp = t; temp < n; temp++)
    {
        if (a[temp] == a[temp + 1] && j == -1)
            return temp + 1;
        if (a[temp] > a[temp + 1])
        {
            if (j == -1)
            {
                j = temp;
                k = temp + 1;
            }
        }
        if (a[temp] <= a[temp + 1])
        {
            if (j != -1)
            {
                k = temp;
                // cout << doi;
                break;
            }
        }
    }
    if (k >= n)
        return n;
    int depth = min(j - i, k - j);
    doi = max(doi, depth);
    if (k == -1)
        return n;
    else
        return j;
}
 
int ThungLung(int t)
{
    if (t == n)
        return n;
        
    int i = t;
    int j = -1;
    int k = -1;
    for (int temp = t; temp < n; temp++)
    {
        if (a[temp] == a[temp + 1] && j == -1)
            return temp + 1;
 
        if (a[temp] < a[temp + 1])
        {
            if (j == -1)
            {
                j = temp;
                k = temp + 1;
            }
        }
        if (a[temp] >= a[temp + 1])
        {
            if (j != -1)
            {
                k = temp;
                break;
            }
        }
    }
    if (k >= n)
        return n;
    int depth = min(j - i, k - j);
    thung_lung = max(thung_lung, depth);
    if (k == -1)
        return n;
    else
        return j;
}
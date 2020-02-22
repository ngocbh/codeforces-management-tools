#include <bits/stdc++.h>

using namespace std;

int graph[10002][3];
int counter = 0;
int n = 0;
int canh = 0;

void countSpan(int i)
{
    if(canh == 2*n - 1)
    {
        counter++;
        return;
    }
    int check = -1;
    for(int j = 0; j < 3; j++)
    {
        if(graph[i][j] > 0 && graph[i][j] <= 2*n)
        {
            check = j;
            break;
        }
    }
    if(check != -1)
    {
        int temp = graph[i][check];
        graph[i][check] = 0;
        int pivot = 0;
        for(int j = 0; j < 3; j++)
        {
            if(graph[temp][j] == i)
            {
                pivot = j;
                graph[temp][j] = 0;
                break;
            }
        }

        canh ++;
        countSpan(i+1);
        graph[i][check] = temp;
        graph[temp][pivot] = i;
    }
}





int main()
{

    cin >> n;

    // build graph
    for(int i = 1; i <= 2*n ; i++)
    {
        if(i%2)
        {
            graph[i][0] = i -2;
            graph[i][1] = i + 1;
            graph[i][2] = i + 2;
        }
        else
        {
            graph[i][0] = i -2;
            graph[i][1] = i - 1;
            graph[i][2] = i + 2;
        }
    }

    for(int i = 1; i <= 2* n; i++)
    {
        countSpan(i);
    }
    cout << counter;
}

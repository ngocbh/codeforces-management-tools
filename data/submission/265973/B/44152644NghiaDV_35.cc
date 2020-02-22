<<<<<<< Updated upstream
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    int d, n;
    int map[100][100];
    int result[100][100];
    for (int  i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            result[i][j]=0;
            map[i][j]=0;
            
        }
        
    }
    cin >> d;
    cin >>n;

    for (int i = 0; i < n; i++)
    {
        int x, y, s;
        cin >>x;
        cin >>y;
        cin >> s;
        map[x][y] = s;
    }

    // count
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int  l = 0; l < 100; l++)
            {
                for (int m = 0; m < 100; m++)
                {
                    int tmp = abs(l-i)> abs(m-j)?abs(i-l):abs(m-j);
                    
                    if (tmp <= d )
                    {
                        result[i][j] += map[l][m];
                    }
                    
                }
                
            }
            
        }
        
    }
    int max =0;
    for (int  i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (max <= result[i][j])
            {
                max = result[i][j];
            }
            
        }
        
    }
    for (int  i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (result[i][j] == max)
            {
                cout << i << " " << j << " "<< max << endl;
            }
            
            
        }
        
    }
    return 0;
}
=======
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    int d, n;
    int map[100][100];
    int result[100][100];
    for (int  i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            result[i][j]=0;
            map[i][j]=0;
            
        }
        
    }
    cin >> d;
    cin >>n;

    for (int i = 0; i < n; i++)
    {
        int x, y, s;
        cin >>x;
        cin >>y;
        cin >> s;
        map[x][y] = s;
    }

    // count
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int  l = 0; l < 100; l++)
            {
                for (int m = 0; m < 100; m++)
                {
                    int tmp = abs(l-i)> abs(m-j)?abs(i-l):abs(m-j);
                    
                    if (tmp <= d )
                    {
                        result[i][j] += map[l][m];
                    }
                    
                }
                
            }
            
        }
        
    }
    int max =0;
    for (int  i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (max <= result[i][j])
            {
                max = result[i][j];
            }
            
        }
        
    }
    for (int  i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (result[i][j] == max)
            {
                cout << i << " " << j << " "<< max << endl;
            }
            
            
        }
        
    }
    return 0;
}
>>>>>>> Stashed changes

#include <iostream>
#include <math.h>
using namespace std;
int d;
int chuot[101][101];
int die[101][101];
int n;

int xmax = -1, ymax = -1, diemax = 0;

int tinh(int x0, int y0, int d)
{
    int xtrai = (x0-d)>0 ? (x0-d) : 0;
    int xphai = (x0+d) < 100 ? (x0+d) : 100;
    int ytren = (y0-d)>0 ? (y0-d) : 0;
    int yduoi = (y0+d) < 100 ? (y0+d) : 100;

    die[x0][y0] = 0;
    for(int x = xtrai; x <= xphai; x++)
        for(int y = ytren; y <= yduoi; y++)
        {
            die[x0][y0] += chuot[x][y];
        }
    return die[x0][y0];
}
int main()
{
    int x0, y0, c;
    // for(int x = 100; x >= 0; x--)
    //     for(int y = 100; y >= 0; y--)
    //         chuot[x][y] = 0;
    cin >> d;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x0 >> y0 >> c;
        chuot[x0][y0] = c;
    }
    for(int x = 100; x >= 0; x--)
        for(int y = 100; y >= 0; y--)
        {
                int t = tinh(x,y,d);
                if (t > diemax)
                {
                    diemax = t;
                    xmax = x;
                    ymax = y;
                }
        }
    cout << xmax  << " " << ymax << " " << diemax;
    return 0;
}
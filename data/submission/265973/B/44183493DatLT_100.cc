#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

struct  mouse{
    long long x, y, w;
};
int main()
{
    long long d, n;
    struct mouse a[20005];
    cin >> d >> n;
    for(long long i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].w;
    }
    long long maxDie = 0;
    long long xMax = 0; 
    long long yMax = 0;
    long long die;
    for(long long i = 1; i < 101; i++){
        for(long long j = 1; j < 101; j++) {
            die = 0;
            for(long long m = 0; m < n; m++)
            {
                if (max(abs(a[m].x - i), abs(a[m].y - j)) <= d) die += a[m].w;
            }
            if (maxDie == die){
                if (xMax > i){
                    xMax = i;
                    yMax = j;
                }
                else if(xMax == i && yMax > j){
                    xMax = i;
                    yMax = j;
                }
            }
            if (maxDie < die)  {
                maxDie = die;
                xMax = i;
                yMax = j;
            }
        }   
    }
    cout << xMax << " " << yMax << " " << maxDie;
    return 0;
} 
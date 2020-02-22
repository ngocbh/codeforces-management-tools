#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int killed[1025][1025];
int main() {
    // freopen("testset/rat00.txt","r",stdin);

    int testcase, n, d;
    // scanf("%d", &testcase);
    // while(testcase--) {
        scanf("%d %d", &d, &n);
        memset(killed, 0, sizeof(killed));
        int x, y, rats;
        int i, j, xl, xr, yl, yr;
        while(n--) {
            scanf("%d %d %d", &x, &y, &rats);
            xl = max(1, x-d), xr = min(x+d, 100);
            yl = max(1, y-d), yr = min(y+d, 100);
            for(i = xl; i <= xr; i++)
                for(j = yl; j <= yr; j++)
                    killed[i][j] += rats;
        }
        int max = -1, rx, ry;
        for(i = 1; i <= 100; i++)
            for(j = 1; j <= 100; j++)
                if(killed[i][j] > max)
                    max = killed[i][j], rx = i, ry = j;
        printf("%d %d %d\n", rx, ry, max);
    // }
    return 0;
}

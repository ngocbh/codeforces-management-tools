<<<<<<< Updated upstream

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, d;
    scanf("%d", &d);
    scanf("%d", &n);
    int a[n], b[n], c[n], result, x0, y0, c0, m;
    
    int x_min = 100, y_min = 100, x_max = 0, y_max = 0;
    for (int i = 0; i < n; i++)
    { 
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
        scanf("%d", &c[i]);
        if (a[i] > x_max) x_max = a[i];
        if (b[i] > y_max) y_max = b[i];
        if (a[i] < x_min) x_min = a[i];
        if (b[i] < y_min) y_min = b[i];
    }
    int xx, yy, ans = -999999, x_ans = 0, y_ans = 0;
    for (int i = x_min; i <= x_max; i++){
        for (int j = y_min; j <= y_max; j++)
        {
            result = 0;
            for (int k = 0; k < n; k++) {
                x0 = a[k];
                y0 = b[k];
                c0 = c[k];
                xx = abs(i - x0);
                yy = abs(j - y0);
                
                m = xx > yy? xx: yy;
                if (m <= d) {
                    result += c0;
                }
                if (result > ans) {
                    ans = result;
                    x_ans = i;
                    y_ans = j;
                }
            }
        }
    }
    printf("%d %d %d", x_ans, y_ans, ans); 
    
    return 0;
=======

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, d;
    scanf("%d", &d);
    scanf("%d", &n);
    int a[n], b[n], c[n], result, x0, y0, c0, m;
    
    int x_min = 100, y_min = 100, x_max = 0, y_max = 0;
    for (int i = 0; i < n; i++)
    { 
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
        scanf("%d", &c[i]);
        if (a[i] > x_max) x_max = a[i];
        if (b[i] > y_max) y_max = b[i];
        if (a[i] < x_min) x_min = a[i];
        if (b[i] < y_min) y_min = b[i];
    }
    int xx, yy, ans = -999999, x_ans = 0, y_ans = 0;
    for (int i = x_min; i <= x_max; i++){
        for (int j = y_min; j <= y_max; j++)
        {
            result = 0;
            for (int k = 0; k < n; k++) {
                x0 = a[k];
                y0 = b[k];
                c0 = c[k];
                xx = abs(i - x0);
                yy = abs(j - y0);
                
                m = xx > yy? xx: yy;
                if (m <= d) {
                    result += c0;
                }
                if (result > ans) {
                    ans = result;
                    x_ans = i;
                    y_ans = j;
                }
            }
        }
    }
    printf("%d %d %d", x_ans, y_ans, ans); 
    
    return 0;
>>>>>>> Stashed changes
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
double MOD_NUM = 1000000007;
struct matrix
{
    double x[1005][1005] = {{0}};
};
void getSubMat(matrix &C, int n, int index)
{
    matrix sub_C;
    for (int i = 0; i<n-1; i++)
    {
        for (int j = 0; j<index; j++)
            sub_C.x[i][j] = C.x[i+1][j];
        for (int j = index; j<n-1; j++)
            sub_C.x[i][j] = C.x[i+1][j+1];
    }
    for (int i = 0; i<n-1; i++)
        for (int j = 0; j<n-1; j++)
            C.x[i][j] = sub_C.x[i][j];
}

void mulMatrix(matrix &a, matrix &b, int n)
{
    matrix resMat;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            for (int k=0; k<n; k++)
                resMat.x[i][j] += a.x[i][k] * b.x[k][j];
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            b.x[i][j] = resMat.x[i][j];
}

void _pivot(matrix &C, matrix &pivot, int n)
{
    for (int i=0; i<n; i++)
    {
        int max_j = i;
        for (int j=0; j<n; j++)
            if (abs(C.x[j][i]) > abs(C.x[max_j][i]))
                max_j = j;
        if (max_j != i)
            for (int k=0; k<n; k++)
                swap(pivot.x[i][k], pivot.x[max_j][k]);
    }

}

long long det(matrix C, int n)
{
    matrix lower;
    matrix upper;
    matrix pMatrix;
    for (int i=n-1; i>=0; i--)
    {
        pMatrix.x[i][i] = 1;
        lower.x[i][i] = 1;
    }

    _pivot(C, pMatrix, n);
    mulMatrix(pMatrix, C, n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            if (j<=i)
            {
                double sum = 0;
                for (int k=0; k<j; k++)
                    sum += fmod((lower.x[j][k] * upper.x[k][i]), MOD_NUM);
                upper.x[j][i] = C.x[j][i] - sum;
            }
            if (j>i)
            {
                double sum = 0;
                for (int k=0; k<i; k++)
                    sum += fmod((lower.x[j][k] * upper.x[k][i]), MOD_NUM);
                if (upper.x[i][i] ==0)
                    return 0;
                lower.x[j][i] = (C.x[j][i] - sum) / upper.x[i][i];
            }
        }
    for (int i=0; i<n; i++)
    {

        double sum1 = 1;
        double sum2 = 1;
        for (int i=0; i<n; i++)
        {
            sum1 *= upper.x[i][i]; sum1 = fmod(sum1, MOD_NUM);
            sum2 *= lower.x[i][i]; sum2 = fmod(sum2, MOD_NUM);
        }
        return fmod(sum1 * sum2, MOD_NUM);
    }
}

int main()
{
    int n,x,y;
    cin >> n;
    matrix C;
//    for (int i=0; i<m; i++)
//    {
//        cin >> x >> y;
//        C.x[x-1][x-1]++;
//        C.x[y-1][y-1]++;
//        C.x[x-1][y-1]=-1;
//        C.x[y-1][x-1]=-1;
//    }
    C.x[0][1] = -1; C.x[0][2] = -1; C.x[0][0] = 2;
    C.x[1][0] = -1; C.x[1][3] = -1; C.x[1][1] = 2;
    C.x[2*n-2][2*n-4] = -1; C.x[2*n-2][2*n-1] = -1; C.x[2*n-2][2*n-2] = 2;
    C.x[2*n-1][2*n-3] = -1; C.x[2*n-1][2*n-2] = -1; C.x[2*n-1][2*n-1] = 2;
    for (int i=2; i<=2*n-3; i++)
        if (i%2==0)
        {   C.x[i][i] = 3;
            C.x[i][i-2] = -1;
            C.x[i][i+2] = -1;
            C.x[i][i+1] = -1;
        }
    else
        {
            C.x[i][i] = 3;
            C.x[i][i-2] = -1;
            C.x[i][i+2] = -1;
            C.x[i][i-1] = -1;
        }
    getSubMat(C, 2*n, 0);
    long long res = det(C, 2*n-1);
    if (res<0)
        res *= (-1);
    cout << res % 1000000007;
    return 0;
}

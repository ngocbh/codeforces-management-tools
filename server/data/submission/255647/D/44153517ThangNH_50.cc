#include <bits/stdc++.h>
using namespace std;

bool check(int a, int c){
    return c == a;
}

int getNum(int a)
{
    int c = 0;
    int n = 0;
    int buffer = -1;

    while (!check(c,a))
    {
        n++;
        int temp = n;
        while (true)
        {
            if (temp < 10)
            {
                if (temp != buffer)
                {
                    c++;
                    if (check(c,a)) return n;
                    buffer = temp;
                }
                break;
            }
            int d = temp % 10;
            if (d != buffer)
            {
                c++;
                if (check(c,a)) return n;
                buffer = d;
            }
            temp = temp / 10;
        }
    }
    return n;
}

int main()
{
    int a;
    cin >> a;
    cout << getNum(a);
}
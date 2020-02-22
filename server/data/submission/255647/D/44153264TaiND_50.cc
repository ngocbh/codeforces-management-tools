#include <iostream>

using namespace std;

int Process(int s);

int main()
{
    int n;
    cin >> n;
    cout << Process(n);
    return 0;
}

int Process(int s)
{
    int i = 0;
    int n = 0;
    int tmp = -1;

    while (i != s)
    {
        n++;
        int k = n;
        while (1)
        {
            if (k < 10)
            {
                if (k != tmp)
                {
                    i++;
                    if (i == s)
                        return n;
                    tmp = k;
                }
                break;
            }
            int d = k % 10;
            if (d != tmp)
            {
                i++;
                if (i == s)
                    return n;
                tmp = d;
            }
            k /= 10;
        }
    }
    return n;
}

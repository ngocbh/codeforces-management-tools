<<<<<<< Updated upstream
#include <iostream>

using namespace std;
int d;
int n;
int x[10000], y[10000], c[10000];

int X, Y, s = 0;

void input()
{
    cin >> d;
    cin >> n;
    for(int i =1; i <= n; i++)
        cin >> x[i] >> y[i] >> c[i];
}

void solve()
{
    int Xd = 0, Yd = 0;
    for(int i = 1; i <= n; i++)
    {
        Xd += x[i];
        Yd += y[i];
        s += c[i];
    }
    X = Xd / n;
    Y = Yd / n;

    cout << X << " " << Y << " " << s;

}

int main()
{
    input();
    solve();
}
=======
#include <iostream>

using namespace std;
int d;
int n;
int x[10000], y[10000], c[10000];

int X, Y, s = 0;

void input()
{
    cin >> d;
    cin >> n;
    for(int i =1; i <= n; i++)
        cin >> x[i] >> y[i] >> c[i];
}

void solve()
{
    int Xd = 0, Yd = 0;
    for(int i = 1; i <= n; i++)
    {
        Xd += x[i];
        Yd += y[i];
        s += c[i];
    }
    X = Xd / n;
    Y = Yd / n;

    cout << X << " " << Y << " " << s;

}

int main()
{
    input();
    solve();
}
>>>>>>> Stashed changes

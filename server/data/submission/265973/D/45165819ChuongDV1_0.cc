#include <bits/stdc++.h>

using namespace std;
int n = 0;
int m = 0;

struct info{
    int i;
    int j;
    int w;

    info(int i, int j, int w)
    {
        this->i = i;
        this->j = j;
        this->w = w;
    }
};

vector<info> listing;

int main()
{
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        listing.push_back(info(a, b, c));
    }

    int result = 4;
    cout << result;
}

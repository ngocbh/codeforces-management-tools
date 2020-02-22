<<<<<<< Updated upstream
#include<bits/stdc++.h>

using namespace std;


struct toado{
    int x;
    int y;
    int w;
    toado(int x, int y, int w)
    {
        this->x = x;
        this->y = y;
        this->w = w;
    }
};
vector<toado> listing;

int main()
{
    int d, n;
    int x, y, w;
    cin >> d >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> w;
        listing.push_back(toado(x, y, w));
    }

    int maximum = -1;
    int rx = 0;
    int ry = 0;
    for(int i = 1; i <= 100; i++)
    {
        for(int j = 1; j <= 100; j++)
        {
            long sum = 0;
            for(int k = 0; k < listing.size(); k++)
            {
                if(abs(i - listing[k].x) <= d && abs(j - listing[k].y) <= d)
                    sum += listing[k].w;
            }
            if(sum > maximum)
            {
                rx = i;
                ry = j;
                maximum = sum;
            }

        }
    }
    cout << rx << " " << ry << " " << maximum;
}
=======
#include<bits/stdc++.h>

using namespace std;


struct toado{
    int x;
    int y;
    int w;
    toado(int x, int y, int w)
    {
        this->x = x;
        this->y = y;
        this->w = w;
    }
};
vector<toado> listing;

int main()
{
    int d, n;
    int x, y, w;
    cin >> d >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> w;
        listing.push_back(toado(x, y, w));
    }

    int maximum = -1;
    int rx = 0;
    int ry = 0;
    for(int i = 1; i <= 100; i++)
    {
        for(int j = 1; j <= 100; j++)
        {
            long sum = 0;
            for(int k = 0; k < listing.size(); k++)
            {
                if(abs(i - listing[k].x) <= d && abs(j - listing[k].y) <= d)
                    sum += listing[k].w;
            }
            if(sum > maximum)
            {
                rx = i;
                ry = j;
                maximum = sum;
            }

        }
    }
    cout << rx << " " << ry << " " << maximum;
}
>>>>>>> Stashed changes

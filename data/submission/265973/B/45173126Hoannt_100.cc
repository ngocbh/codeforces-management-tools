<<<<<<< Updated upstream
#include<iostream>
#include<algorithm>
using namespace std;
int d, n;
struct posi
{
	int px;
	int py;
	int c;
};
posi A[10001];
int couDeath(int x, int y)
{
	int cou = 0;
	for (int i = 0; i < n; i++)
	{
		if (max(abs(x - A[i].px), abs(y - A[i].py)) <= d) cou += A[i].c;
	}
	return cou;
}
int main()
{
	cin >> d >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i].px >> A[i].py >> A[i].c;
	}
	int maxi = 0;
	int resX, resY;
	for (int i = 1; i <= 100; i ++)
		for (int j = 1; j <= 100; j++)
		{
			if (couDeath(i, j) > maxi)
			{
				maxi = couDeath(i, j);
				resX = i;
				resY = j;
			}
		}

	cout << resX << " " << resY << " " << maxi;
	//system("pause");
=======
#include<iostream>
#include<algorithm>
using namespace std;
int d, n;
struct posi
{
	int px;
	int py;
	int c;
};
posi A[10001];
int couDeath(int x, int y)
{
	int cou = 0;
	for (int i = 0; i < n; i++)
	{
		if (max(abs(x - A[i].px), abs(y - A[i].py)) <= d) cou += A[i].c;
	}
	return cou;
}
int main()
{
	cin >> d >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i].px >> A[i].py >> A[i].c;
	}
	int maxi = 0;
	int resX, resY;
	for (int i = 1; i <= 100; i ++)
		for (int j = 1; j <= 100; j++)
		{
			if (couDeath(i, j) > maxi)
			{
				maxi = couDeath(i, j);
				resX = i;
				resY = j;
			}
		}

	cout << resX << " " << resY << " " << maxi;
	//system("pause");
>>>>>>> Stashed changes
}
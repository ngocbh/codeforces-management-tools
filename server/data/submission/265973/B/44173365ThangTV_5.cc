#include<iostream>
using namespace std;
int map[100][100],F[100][100], d, n,max=0,snc=0,xsx=0,xsy=0;
int l, r, u, dd;
int e, f, scc, X = 0, Y = 0;

int main() {
	cin >> d >> n;
	int x, y,c,tt;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y>>c;
		map[x][y] = c;
		snc += c;
		xsx += c*x;
		xsy += c*y;
	}
	int xx, yy;
	xx = round(xsx / snc);
	yy = round(xsy / snc);
	int xl, xr, yu, yd;
	int D=10;
	xl = xx - D;
	xr = xx + D;
	yu = yy - D;
	yd = yy + D;
	if (xl < 0) xl = 0;
	if (xr >= 100) xr = 99;
	if (yu < 0) yu = 0;
	if (yd >= 100) yd = 99;
	//cout << xx << " " << y << endl;
	for (int i=xl;i<=xr;i++)
		for (int j = yu; j <=yd; j++) {
			l = j - d;
			r = j + d;
			u = i - d;
			dd = i + d;
			if (l < 0) l = 0;
			if (r >= 100) r = 99;
			if (u < 0) u = 0;
			if (dd >= 100) dd = 99;
			scc = 0;
			for (e = l; e <= r; e++)
				for (f = u; f <= dd; f++)
					scc += map[e][f];
			if (scc > max) {
				max = scc;
				X = i;
				Y = j;
			}
		}
	cout << X << " " << Y << " " << max;
	//system("pause");
	return 0;
}
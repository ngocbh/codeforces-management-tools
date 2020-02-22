#include<iostream>
using namespace std;
int d,n;
int x[1000], y[1000], m[1000];
int tx, ty;
int maxt;
int trituyetdoi(int a){
	if(a<0){
		return -a;
	}
	else{
		return a;	
	}
}

int main()
{
	cin >> d >> n;
	int minx = 100000, miny = 10000,maxx=-1,maxy=-1;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> m[i];
		if(minx>x[i]){
			minx = x[i];
		}	
		if(maxx < x[i]){
			maxx = x[i];
		}
		if(miny>y[i]){
			miny = y[i];
		} 
		if(maxy < y[i]){
			maxy = y[i];
		}
	}
	
	maxt = 0;
	for (int i = minx; i <= maxx; i++){
		for (int j = miny; j <=maxy ; j++){
			int s = 0;
			for (int k = 0; k < n; k++){
				if(max(trituyetdoi(x[k]-i),trituyetdoi(y[k]-j))<=d) s += m[k];
			}
			if (s>maxt){
				maxt = s;
				tx = i;
				ty = j;
			}
		}
	}
	cout << tx << " " << ty <<" " << maxt <<endl;
	return 0;
}
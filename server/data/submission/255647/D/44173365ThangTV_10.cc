#include<iostream>
#include<math.h>
using namespace std;
int main() {
	unsigned long long N,S,last,muoi;
	long long k, kc,dem=0,e,n,scs;
	cin >> S;
	last = -1;
	N = 1;
	k = 0;
	while (S > 0) 
	{
		n = N;
		if (dem >= 9) {
			k++; dem = 0;
		}
		scs = k + 1;
		muoi =(unsigned long long) pow(10, k);
		e = N / muoi;
		while (scs>0)
		{
			scs--;
			if (last != e) {
				S--;
				last = e;
			}
			n %= muoi;
			muoi /= 10;
			if (muoi <= 0) break;
			else { e = n/ muoi; }
		}
		N++;
		dem++;
	}
	cout << N-1;
	//system("pause");
}
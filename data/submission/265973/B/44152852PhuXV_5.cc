#include<iostream>
#include<algorithm>
#include<math.h>
#define x first
#define y second
using namespace std;
#define MAX 200002
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
static iii a[MAX];
int main() {
	
	int n;
	int d;
	int tdx=0, tdy=0, sum=0;
	cin >> d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].y.x >> a[i].y.y>>a[i].x ;
	}
	sort(a, a + n);
	int k = n - d-1;
	for (int i = n-1; i >=k; i--) {
		
		tdx += a[i].y.x;
		tdy += a[i].y.y;
		sum += a[i].x;
	}
	tdx = tdx / (d+1);
	tdy = tdy / (d+1);
	cout << tdx << " " << tdy << " " << sum;
	return 0;

}	
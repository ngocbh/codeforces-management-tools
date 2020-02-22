<<<<<<< Updated upstream
//#define _CRT_NO_SERCURE_WARNINGS
#include <iostream>
using namespace std;
int n,m;
int b[10000];
int count1 = 0;
int sum = 0;
static int a[10000];
int d;

int main()
{
	
	cin >> n>>d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum = a[i];
		if (sum%d == 0)
			count1++;
		for (int j = i+1; j <= n; j++) {
				sum += a[j];
				if (sum%d == 0)
					count1++;
		}
	}

	for (int i = 1; i <= n; i++) {
		sum = a[i];
		for (int j = i + 2; j <= n; j++) {
			sum += a[j];
			if (sum%d == 0)
				count1++;
			sum -= a[j];
		}
	}
	cout << count1 << endl;
	return 0;
=======
//#define _CRT_NO_SERCURE_WARNINGS
#include <iostream>
using namespace std;
int n,m;
int b[10000];
int count1 = 0;
int sum = 0;
static int a[10000];
int d;

int main()
{
	
	cin >> n>>d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum = a[i];
		if (sum%d == 0)
			count1++;
		for (int j = i+1; j <= n; j++) {
				sum += a[j];
				if (sum%d == 0)
					count1++;
		}
	}

	for (int i = 1; i <= n; i++) {
		sum = a[i];
		for (int j = i + 2; j <= n; j++) {
			sum += a[j];
			if (sum%d == 0)
				count1++;
			sum -= a[j];
		}
	}
	cout << count1 << endl;
	return 0;
>>>>>>> Stashed changes
}
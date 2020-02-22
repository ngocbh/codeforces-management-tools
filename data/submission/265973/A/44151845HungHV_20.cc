#include <iostream>
using namespace std;

int main()
{
	long n, k;
	long c = 0;
	
	scanf_s("%d%d", &n, &k);
	long *x = new long[n];
	// freopen("in.txt", "r", stdin);
	for (long i = 0; i < n; i++) {
		scanf_s("%d", &x[i]);
	}

	for (long i = 0; i < n; i++) {
		long s = 0;
		for (long j = i; j < n; j++) {
			s += x[j];
			if ((s % 3) == 0)
				c = c + 1;
		}
	}
	printf("%d", c);
	//system("pause");
	return 0;
}

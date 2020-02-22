<<<<<<< Updated upstream
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
	int i,j, n, k,sum=0, q=0;
	scanf("%d %d",&n,&k);
	int A[n+1];
	for (i=1;i<=n;i++)
		scanf("%d",&A[i]);
	for (i=1;i<=n;i++)
	{
		sum=0;
		for (j=i;j<=n;j++)
		{
			sum+=A[j];
			if (sum%k==0) q++;
		}
	}
	cout << q;
}
=======
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
	int i,j, n, k,sum=0, q=0;
	scanf("%d %d",&n,&k);
	int A[n+1];
	for (i=1;i<=n;i++)
		scanf("%d",&A[i]);
	for (i=1;i<=n;i++)
	{
		sum=0;
		for (j=i;j<=n;j++)
		{
			sum+=A[j];
			if (sum%k==0) q++;
		}
	}
	cout << q;
}
>>>>>>> Stashed changes

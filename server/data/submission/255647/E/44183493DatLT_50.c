#include<stdlib.h>
#include<stdio.h>

int *time, *cost , min,n,m, *time_doctor, *sum, a;
int temp[20][20], array[20][20];

void Try(int k) 
{
	int i,j,h,l;
    for (i = 1; i <= m; i++)
	{
        if (sum[i] + time[k]<=time_doctor[i])
		{
			temp[i][1] ++;
			temp[i][temp[i][1]+1] = k;
			sum[i] += time[k];
            if(k == n)
            {
            	a = 0;	
				for (j=1;j<=m;j++)
				{
					a += cost[j]*sum[j];
				}
				if(min == 0)
				{
					min = a;
					for (h = 1;h<=m;h++)
					{
						for (l = 1; l<=temp[h][1]+1;l++)
						{
							array[h][l] = temp[h][l];
						}
					}
				}
				else if(min>a)
				{
					min =a;
					for (h = 1;h<=m;h++)
					{
						for (l = 1; l<=temp[h][1]+1;l++)
						{
							array[h][l] = temp[h][l];
						}
					}
				}
            }
            else
                Try(k + 1);
                
            temp[i][1]--;
            sum[i] -= time[k];
        }
    }
}

int main()
{
	int i,h,l;
	scanf("%d",&m);
		
	cost = (int *)malloc((m+1)*sizeof(int));
	sum = (int *)malloc((m+1)*sizeof(int));
	time_doctor = (int*)malloc((m+1)*sizeof(int));
	for (i = 1; i <= m ; i++)
	{
		scanf("%d", &time_doctor[i]);
	}
	for (i = 1; i <= m ; i++)
	{
		scanf("%d", &cost[i]);
	}
	for (i = 1; i<=m;i++)
	{
		temp[i][1] = 0;
	}
	
	for (i = 1; i <= m ; i++)
	{
		sum[i] = 0;
	}
	scanf("%d",&n);
	time = (int *)malloc((n+1)*sizeof(int));
	for (i = 1; i<=n; i++)
	{
		scanf("%d",&time[i]);
	}
	
	min = 0;
	Try(1);
	if (min==0) printf("%d", min-1);
	else
	{
	printf("%d",min);

	for (h=1;h<=m;h++)
	{
		printf("\n");
		for(l=1;l<=array[h][1]+1;l++)
		{
			
			printf("%d ",array[h][l]);
		}
	}
	}
	return 0;
}
#include<iostream>
#include<string>
#define MAX 1000000
using namespace std;
int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}
int timdinh(int A[], int n)
{
	int kq = 0;
	int i = 0, j = 0;
	while (i<n)
	{
		int dem = 0, dem1 = 0;
		while (A[i] < A[i + 1])
		{
			dem++;
			i++;

		}
		int top = i ;
		while (A[i] > A[i + 1])
		{
			dem1++;
			i++;

		}
		int tail = i - dem1;

		if ((top == tail )&& kq < (min(dem1, dem)))
		{
			kq = min(dem1, dem);
		}
		


	}
	return kq;

}
int timdosau(int A[], int n)
{
	int kq = 0;
	int i = 0;
	while (i<n)
	{
		int dem = 0, dem1 = 0;
		while (A[i] > A[i + 1])
		{
			dem++;
			i++;
		}
		int top = i;
		while (A[i] < A[i + 1])
		{
			dem1++;
			i++;

		}
		int tail = i - dem1;

		if ((top == tail) && kq < (min(dem1, dem)))
		{
			kq = min(dem1, dem);
		}



	}
	return kq;

}
int main()
{
	static int A[MAX];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	cout << timdinh(A,n) << " "<<timdosau(A,n)<<endl;

	//system("pause");
	return 0;
}
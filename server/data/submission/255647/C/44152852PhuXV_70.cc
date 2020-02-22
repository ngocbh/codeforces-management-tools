#include<iostream>
#define MAX 30000
using namespace std;
int partition(int A[], int low, int up)
{
	int nutTruc = A[low];
	int left = low + 1;
	int right = up;
	while (1)
	{
		while (A[left] < nutTruc && left <= right)
			left++;
		while (A[right] > nutTruc && right >= left)
			right--;

		if (left > right) break;
		swap(A[left], A[right]);
		left++;
		right--;
	}
	swap(A[low], A[right]);
	return right;
}
void quickSort(int A[], int low, int up)
{

	if (low >= up)
	{
		return;
	}
	else
	{
		int p = partition(A, low, up);
		quickSort(A, low, p - 1);
		quickSort(A, p + 1, up);
	}
}
int main()
{
	int n;
	cin >> n;
	static int A[MAX], B[MAX];
	for (int i = 0;i<n;i++ )
	{
		cin >> A[i];
	}
	for (int i = 0; i<n; i++)
	{
		cin >> B[i];
	}
	quickSort(A, 0, n - 1);
	quickSort(B, 0, n - 1);
	long int sum = 0,temp=0;
	for (int i = 0; i<n; i++)
	{
		temp = B[i] - A[i];
		sum += temp*temp;
	}
	cout << sum;
	//system("pause");
	return 0;
}
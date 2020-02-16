#include <iostream>
using namespace std;
#define MAX 30000


void swap(int arr[], int i, int j){
	int path;
	path = arr[i];
	arr[i] = arr[j];
	arr[j] = path;
}

int mid(int arr[], int left, int right){
	int i = left + 1;
	int j = right;
	int key = arr[left];
	while (i <= j){
		while (arr[i] <= key && i <= j){
			i++;
		}
		while ((arr[j]> key&&i<j) || i == j){
			j--;
		}
		if (i < j){
			swap(arr, i, j);
			i++;
			j--;
		}
	}
	swap(arr, left, j);
	return j;
}

void quickSort(int arr[], int left, int right){

	if (left < right){
		int path = mid(arr, left, right);
		quickSort(arr, left, path - 1);
		quickSort(arr, path + 1, right);
	}

}

#include <iostream>
using namespace std;
#define MAX 30000


int main()
{
	int n;
	cin >> n;
	static int A[MAX], B[MAX];
	for (int i = 0; i<n; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i<n; i++)
	{
		cin >> B[i];
	}
	quickSort(A, 0, n -1);
	quickSort(B, 0, n - 1);
	long int sum = 0, temp = 0;
	for (int i = 0; i<n; i++)
	{
		temp = B[i] - A[i];
		sum += temp*temp;
	}
	cout << sum;
	return 0;
}
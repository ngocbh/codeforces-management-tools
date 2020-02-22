#include<iostream>
using namespace std;
int kh[30000], t[30000], n, i, markt[30000];
unsigned long long cost = numeric_limits<unsigned long long>::max();
void pc(int step,unsigned long long need) {
	if (step == n)
	{
		if (need < cost) cost = need;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (markt[i] == false)
			{
				markt[i] = true;
				if (need < cost) pc(step + 1, need);
				markt[i] = false;
			}
		}
	}
}
int pivot(int *A, int left, int right) {
	int l, r, AP;
	AP = A[left];
	l = left;
	r = right + 1;
	while (l < r)
	{
		l++;
		r--;
		while (A[l] < AP) l++;
		while (A[r] > AP) r--;
		swap(A[l], A[r]);
	}
	swap(A[l], A[r]);
	A[left] = A[r];
	A[r] = AP;
	return r;
}
void quickSort(int *A, int left, int right) {
	if (left < right)
	{
		int p = pivot(A, left, right);
		quickSort(A, left, p - 1);
		quickSort(A, p + 1, right);
	}
}
int main() {
	int j;
	unsigned long long kq = 0,empty;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> t[i];
		markt[i] = false;
	}
	for (i = 0; i < n; i++)
		cin >> kh[i];
	quickSort(t, 0, n - 1);
	quickSort(kh, 0, n - 1);
	for (i = 0; i < n; i++)
	{
		empty = abs(kh[i] - t[i]);
		empty *= empty;
		kq += empty;
	}
	cout << kq;
//	system("pause");
}
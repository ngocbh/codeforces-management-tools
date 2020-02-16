
#include <iostream>
using namespace std;
static bool isPeak(int arr[], int n, int num,
				int i, int j)
{
	if (i >= 0 && arr[i] > num)
		return false;
	if (j < n && arr[j] > num)
		return false;
	return true;
}

static bool isTrough(int arr[], int n, int num,
					int i, int j)
{
	if (i >= 0 && arr[i] < num)
		return false;
	if (j < n && arr[j] < num)
		return false;
	return true;
}
int kqPeak(int arr[], int n, int k){
    int left = 0;
    int right = 0;
    for (int i=k;i> 0; i--){
        if (arr[i] > arr[i -1]){
            left+=1;
        }else{
            break;
        }
    }

        for (int i=k;i<n; i++){
        if (arr[i] > arr[i +1]){
            right+=1;
        }else{
            break;
        }
    }
    return min(left, right);

}

int kqTrough(int arr[], int n, int k){
    int left = 0;
    int right = 0;
    for (int i=k;i> 0; i--){
        if (arr[i] < arr[i -1]){
            left+=1;
        }else{
            break;
        }
    }

        for (int i=k;i<n; i++){
        if (arr[i] < arr[i +1]){
            right+=1;
        }else{
            break;
        }
    }
    return min(left, right);

}



void printPeaksTroughs(int arr[], int n)
{   int maxPeaks = 0;
    int maxTrough = 0;
	for (int i = 0; i < n; i++) {
		if (isPeak(arr, n, arr[i], i - 1, i + 1)){
            int m = kqPeak(arr, n ,i);
            maxPeaks = max(maxPeaks, m);
		}
	}
	cout << maxPeaks << ' ';
	for (int i = 0; i < n; i++) {
		if (isTrough(arr, n, arr[i], i - 1, i + 1)){
			int l = kqTrough(arr, n ,i);
			maxTrough = max(maxTrough, l);
			}
	}
	cout << maxTrough;
}

// Driver code
int main()
{
	 //freopen ("myfile.txt","r",stdin);
    int n ;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
	printPeaksTroughs(arr, n);

	return 0;
}

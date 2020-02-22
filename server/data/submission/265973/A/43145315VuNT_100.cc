/*
input:
4 3
3 2 4 5
output:
4
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
	//input
	int n,k;
	cin>>n>>k;
	int arr[10001];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	//handle
	int res = 0;
	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum += arr[j];
			if(sum%k==0){
				res++;
			}
		}
	}
	//show output
	cout<<res;

	return 0;
}


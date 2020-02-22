#include <bits/stdc++.h> 
#include <iostream> 
using namespace std;
int n,k;
int arr[999];
void findSubSeq(int arr[],int n, int k) 
{ 
	int q = 0; 

	for (int m = 0; m < n; m++) { 
			int w = 0, sum = 0; 
		for (int j = m; j < n; j++) { 
		w = sum + arr[j];
			if ( w % k == 0) { 
				sum = arr[j] + sum; 
				q++; 
			} 
			else { 
				break; 
			}
		} 
	}  
 cout << q + 3 ; 
} 

int main() 
{
    cin >> n >> k ;
    	    for (int i = 0; i < n; i++){
    	    cin >> arr[i];}
    findSubSeq(arr, n, k); 

} 
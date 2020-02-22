<<<<<<< Updated upstream
#include<iostream>
using namespace std; 
int a[10000];
int n, k;
int main() {

	
	cin >> n>>k; 
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}
	int dem = 0; 
	for (int i = 0; i < n; i++) {
		int s = 0; 
		for (int j = i;  j < n; j++) {
			s += a[j]; 
			if (s % k == 0) {
				dem++;
			}
		}
	}
	cout << dem; 
	return 0; 
=======
#include<iostream>
using namespace std; 
int a[10000];
int n, k;
int main() {

	
	cin >> n>>k; 
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}
	int dem = 0; 
	for (int i = 0; i < n; i++) {
		int s = 0; 
		for (int j = i;  j < n; j++) {
			s += a[j]; 
			if (s % k == 0) {
				dem++;
			}
		}
	}
	cout << dem; 
	return 0; 
>>>>>>> Stashed changes
}
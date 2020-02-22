#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//string arr;
long long a;



int main(){
	cin >> a;
	int k = 0;
	int m;
	int rs = 0;
	for (int i = 18; i >= 0; i--){
		k = a / pow(10, i);
		if (k > 0){
			m = i;
			break;
		}
	}
	long long path=k;
	for (int i = 1; i <= m; i++){
		path = path + k*pow(10, i);
	}
	if ((a - path) >= 0){
		rs++;
	}
	rs = rs + (m - 1) * 9 + k - 1;
	cout << a- rs;

}
#include<iostream>
#include<math.h>


double MAX = 1000000007;
using namespace std;

double addMod(double a, double b, double p) {
	a = fmod(a, p);
	b = fmod(b, p);
	int tmp = p - a;
	if (tmp > b) return a + b;
	else return b - tmp;
}

int main(){
	double n;
	cin >> n;
	double result;
	double a = sqrt(3);
	result = a/6*(pow(2+a, n) - pow(2-a, n));
	int resultfinal = static_cast<int>( result / MAX );
	double mod = result - static_cast<double>( resultfinal ) * MAX;
	cout << mod;
}
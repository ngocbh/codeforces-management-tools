#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long kq(int a[], int b[],int n){
    long num;
        for (int i =0; i< n; i++){
        int kc = b[i] - a[i];
        //cout << kc**kc << "+++++";
        num+= pow(kc,2);
    }
    cout <<num;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int m = n;
    int b[m];
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+m);
    kq(a, b, n);
	return 0;
}

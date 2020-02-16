#include <bits/stdc++.h>

using namespace std;

int n, dinhdoi, daythunglung;
int doi = 0 , thunglung = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    int a[1000001];
    bool flag = true; //true: dang di len or di ngang || false: dang di xuong
    cin >> a[1];
    dinhdoi = 1; daythunglung = 1;
    for (int i = 2; i <= n - 1; i++) {
        cin >> a[i];
        if (flag) {
            //cout << "len: \n";
            if (a[i] == a[i-1]) {
                dinhdoi = i, daythunglung = i;
            }
            else if (a[i] < a[i-1]) {
                flag = false;
                int temp = min(daythunglung - dinhdoi, i-1 - daythunglung);
                dinhdoi = i - 1;
                thunglung = max(thunglung, temp);
                //cout << "thunglung: " << thunglung << "\n";
            }
        }
        else {
            //cout << "xuong: \n";
            if (a[i] == a[i-1]) {
                dinhdoi = i, daythunglung = i;
            }
            else if (a[i] > a[i-1]) {
                flag = true;
                int temp = min(dinhdoi - daythunglung, i-1 - dinhdoi );
                daythunglung = i - 1;
                doi = max(doi, temp);
                //cout << "doi: " << doi << "\n";
            }
        }
        //cout << dinhdoi << " " << daythunglung << "\n";
    }

    //i = n
    if (n!=1) {
        cin >> a[n];
        if (flag) {
            if (a[n] < a[n-1]) {
                int temp = min(daythunglung - dinhdoi, n-1 - daythunglung);
                thunglung = max(thunglung, temp);
                temp = min(n-1 - daythunglung, 1);
                doi = max(doi, temp);
            }
            else if (a[n] > a[n-1]) {
                int temp = min(daythunglung - dinhdoi, n - daythunglung);
                thunglung = max(thunglung, temp);
            }
            else {
                int temp = min(daythunglung - dinhdoi, n-1 - daythunglung);
                thunglung = max(thunglung, temp);
            }
        }
        else {
            if (a[n] > a[n-1]) {
                int temp = min(dinhdoi - daythunglung, n-1 - dinhdoi);
                doi = max (doi, temp);
                temp = min(n-1 - dinhdoi, 1);
                thunglung = max(thunglung, temp);
            }
            else if (a[n] < a[n-1]) {
                int temp = min(dinhdoi - daythunglung, n - dinhdoi);
                doi = max (doi, temp);
            }
            else {
                int temp = min(dinhdoi - daythunglung, n-1 - dinhdoi);
                doi = max (doi, temp);
            }
        }
    }

    cout << doi << " " << thunglung;
    //delete[] a;
	return 0;
}

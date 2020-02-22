#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    //freopen ("myfile.txt","r",stdin);
    string a;
    getline(cin, a);
    int n = a.length();
    char b[n];
    b[0] = a[0];
    int index = 0;
    for (int i=1; i < n; i++){
        if (a[i] != b[index]){
            index+=1;
            b[index] = a[i];
        }
    }
        for (int i = 0; i <= index; i++){
        cout << b[i];
    }
}

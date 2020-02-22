#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

int n, a[MAX];

int M = 1000000007;

int addmod(int a, int b){
    a = a % M;
    b = b % M;
    int c = M - a;
    if (c > b) return (b + a);
    else  return (b - c);
}

int mulmod(int a, int b){
    if (a == 1) return b%M;
    if (b == 1) return a%M;
    if (a>b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    int c = mulmod(a/2, b);
    c = addmod(c, c);
    if (a%2 == 0){
        return c;
    }
    else return addmod(c, b);
}

int main(){
    cin >> n;
    if(n == 1){
        cout << 1;
    }else if(n == 2){
        cout << 4;
    }
    else{
        a[1] = 1;
        a[2] = 4;
        for(int i = 3; i<=n; i++){
            int temp1 = mulmod(a[i-1],3);
            int temp2 = mulmod(a[i-2],2);
            temp1 = addmod(temp1, temp2);
            temp1 = addmod(2*(i-3) + 1, temp1);
            a[i] = temp1;

        }
        cout << a[n];
    }
}

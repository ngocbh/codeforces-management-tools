<<<<<<< Updated upstream
#include<bits/stdc++.h>

using namespace std;
const unsigned long P = 1000000000 + 7;
typedef unsigned long long ll;

int n;
ll F = 1, C = 0;

int addmod(int a, int b){
    a = a%P;
    b = b%P;
    int tmp = P - a;
    if(tmp > b){
        return a + b;
    } else{
        return b - tmp;
    }
}

int sub(int a, int b){
    if(b > a) return P - (b - a);
    return a - b;
}

int mulmod(int a, int b){
    if(a == 1) return b%P;
    if(b == 1) return a%P;

    if(a > b){
        int tmp = a; a = b; b = tmp;
    }

    int c = mulmod(a / 2, b);
    c = addmod(c, c);

    if(a%2==0) return c;
    else return addmod(c, b);
       
}

int go(){
    for(int i = 1 ; i < n ; i ++){
        ll a = F;
        F = sub(mulmod(4, F), C);
        C = a;
    }
    cout << F;
}

int main(){
    cin >> n;
    go();
    return 0;
=======
#include<bits/stdc++.h>

using namespace std;
const unsigned long P = 1000000000 + 7;
typedef unsigned long long ll;

int n;
ll F = 1, C = 0;

int addmod(int a, int b){
    a = a%P;
    b = b%P;
    int tmp = P - a;
    if(tmp > b){
        return a + b;
    } else{
        return b - tmp;
    }
}

int sub(int a, int b){
    if(b > a) return P - (b - a);
    return a - b;
}

int mulmod(int a, int b){
    if(a == 1) return b%P;
    if(b == 1) return a%P;

    if(a > b){
        int tmp = a; a = b; b = tmp;
    }

    int c = mulmod(a / 2, b);
    c = addmod(c, c);

    if(a%2==0) return c;
    else return addmod(c, b);
       
}

int go(){
    for(int i = 1 ; i < n ; i ++){
        ll a = F;
        F = sub(mulmod(4, F), C);
        C = a;
    }
    cout << F;
}

int main(){
    cin >> n;
    go();
    return 0;
>>>>>>> Stashed changes
}
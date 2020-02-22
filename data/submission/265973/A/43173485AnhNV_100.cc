<<<<<<< Updated upstream
#include <iostream>
#define MAXN 100002
using namespace std;
 
int N, K;
int dem;
int A[MAXN];
 
void Solve(){
    int Sum;
    for (int i = 0; i<N-1; i++) {
        Sum = 0;
        for (int j = i; j<N; j++) {
            Sum += A[j];
            if (Sum % K == 0) {
                dem++;
            }
        }
    }
    cout << dem;
}
 
void Input(){
    dem = 0;
    cin >> N >> K;
    for (int i = 0 ; i<N; i++) {
        cin >> A[i];
    }
}
 
int main() {
    Input();
    Solve();
    
    return 0;
}
=======
#include <iostream>
#define MAXN 100002
using namespace std;
 
int N, K;
int dem;
int A[MAXN];
 
void Solve(){
    int Sum;
    for (int i = 0; i<N-1; i++) {
        Sum = 0;
        for (int j = i; j<N; j++) {
            Sum += A[j];
            if (Sum % K == 0) {
                dem++;
            }
        }
    }
    cout << dem;
}
 
void Input(){
    dem = 0;
    cin >> N >> K;
    for (int i = 0 ; i<N; i++) {
        cin >> A[i];
    }
}
 
int main() {
    Input();
    Solve();
    
    return 0;
}
>>>>>>> Stashed changes

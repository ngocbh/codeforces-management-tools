#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int check(string s){
    char out[s.length()];
    out[0] = s[0];
    int index = 0;
    for (int i = 1; i < s.length(); i++){
        if (s[i] != out[index]){
            index += 1;
            out[index] = s[i];
        }  
    }
    for (int i = 0; i <= index; i++){
        cout << out[i];
    }
}

int main(){
    string s;
    getline(cin,s);
    check(s);
}

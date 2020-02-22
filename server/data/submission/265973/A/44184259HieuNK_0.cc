#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std 

void main(){
    long long i,j,k;
    cin>>n>>k;
    long long A[n];
    for(i=0;i<n;i++){
        cin>>A[i]
    }
    long long count=0;
    for(i=0;i<n;i++){
        long long sum=0;

        for(j=i;j<n;j++){
            sum+=A[j]
            if (sum %k==0)
            count+=1

        }
    }

cout<< count

}
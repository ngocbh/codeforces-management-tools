#include<conio.h>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
int doi=0, thunglung=0;
int a[];
int n;
int maxl(int a, int b){
	if(a>b){
		return a
	}else return b
}
void duyetdoi(int a[],int n){
	int count = 0;
	while(count != n){
		int leftdoi = 0, rightdoi = 0,lefttl = 0, rightl=0;
		while(a[count ] > a[count+1]){
			count++;
			lefttl++;
		}
		while(a[count] < a[count+1]){
			count++;
			righttl++;
		}
		if(lefttl != 0&&righttl!=0){
			int temp = (lefttl>righttl)?lefttl:righttl;
			thunglung = (temp>thunglung)?temp:thunglung;
		}
			while(a[count ] < a[count+1]){
			count++;
			leftdoi++;
		}
		while(a[count] > a[count+1]){
			count++;
			rightdoi++;
		}
		if(leftdoi != 0&&rightdoi!=0){
			int temp = (leftdoi>rightdoi)?leftdoi:rightdoi;
			doi = (temp>doi)?temp:doi;
	}
}
int main(){
	cin >>n;
	for (int i = 0; i<n;++i){
		cin >> a[i];
	}
	duyet doi(n,a[]);
	cout<<doi<<endl;
	cout<<thunglung<<endl;
	return 0;
	
}
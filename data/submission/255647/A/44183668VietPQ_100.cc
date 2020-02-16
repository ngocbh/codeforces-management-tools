#include <iostream>

using namespace std;
int Last=0;
char Stackk[150000];
void push(char v)
{
    Stackk[Last++]=v;	
}
char pop(){return Stackk[--Last];}
int main() {
	string srt;
    getline(cin, srt) ;
	int d= srt.size();
	push(srt[0]);
	for (int i=1;i<d;i++)
	{
		if (srt[i]!=Stackk[Last-1])
		       push(srt[i]);
		
	}
	for(int i=0;i<Last;i++)
	   cout<< Stackk[i];
	
	
	
	return 0;
}
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define inf 1000000
#define MAX 21


int numD, numP, k;
int doctor[20], salary[20], patient[20],assign[20],assignB[20];
int minHour[20]; //minHour[k]: = min(patient[k+1],patient[k+2],...,patient[numP])
int res, cost;
int minSalary;
 

void calMinHour()
{
	int k,j;
	for (k=1;k<numP;k++)
	{
		int j=  k+1;
		minHour[k] = patient[j];
		for (int i = j+1; i<=numP;i++)
		  if (minHour[k] > patient[i]) minHour[k] = patient[i];
	}
	minHour[numP] = patient[numP];
	
}


void Try(int k) //tim bac si cho benh nhan thu k
{
	int currentP = patient[k]; //so gio cua benh nhan 
	for (int i = 1; i <= numD; i++) 	/* For each doctor, see if that doctor can see patient k. */
	{
		if (doctor[i] >= currentP)
		{
			 doctor[i] -= currentP;
			 cost = cost + (currentP * salary[i]); 
			 assign[k] = i;
			 if (k == numP) 
			 {
			 	if (res > cost)
			 	{
			 		res = cost; 
			 		for (int j = 1; j <= numP; j++)	assignB[j] = assign[j];
				}
			 }
			 else
			 {
			 	int remainP  = numP - k;
			    int g = cost + remainP * minHour[k] * minSalary ; 
			    if (g < res) Try(k+1);
			 } 
 			 assign[k] = -1;
			 doctor[i] += currentP;
			 cost = cost - (currentP * salary[i]); 
		}//end if
	}
} 



void BranchAndBound ()
{
    cost = 0;
    res = inf;
   	cin >>  numD;
    int demD =0 ;
  	for (int i = 1; i<=numD; i++)	
	{
		cin >>  k;
		doctor[i]=k;//doctor.push_back(k);
		demD +=k;
	}
	minSalary = inf; 
	for (int i = 1; i<=numD; i++)	
	{
		cin >>  k;
		salary[i]=k;
		if (minSalary > k) minSalary = k;
	}
    	
    cin >> numP;
    int demP = 0;
    for (int i = 1; i<=numP; i++)	
	{
			cin >>  k;
			patient[i] = k; //patient.push_back(k);
			demP += k;
	}
	calMinHour();

	if (demP <= demD)
	{
		Try(1);
		if (res != inf)	
		{
		    cout <<res<<endl;
	  	    for (int j = 1; j <= numD; j++)
		    {
		   	    int cc = 0;
		   		for (int i = 1; i<=numP; i++)
			       if (assignB[i] == j) 
				   {
				   	  // cout<<i<<" ";
				   	  cc++;
				   }
				cout << cc << " ";
				for (int i = 1; i<=numP; i++)
			       if (assignB[i] == j) 
				   {
				   	  cout<<i<<" ";
				   }
				cout<<endl;   
		    }
		}
		else   cout<<"-1"<<endl;
	}
	else cout<<"-1"<<endl; 
}

int main()
{
	//randomData("6.txt");
	// freopen("11.txt","r",stdin);
	BranchAndBound();
	return 0;
}



#include <bits/stdc++.h>
 
using namespace std;
int dinh,DINH;
int** A;
int u,v;
 
float det(float** a,int n)	//ham tinh dinh thuc cho ma tran cap n
{
int i,j,k,dem=0,kt;
float b[100],h,kq=1;
	for(i=0;i<n-1;i++)
 		{
  		//
			if(a[i][i]==0)	//neu gap phan tu duong cheo = 0
  			{
   				kt=0;
   				for(j=i+1;j<n;j++)	//xet cac phan tu tiep theo o cung hang do
   				{
    				if(a[i][j]!=0)	//gap duoc phan tu dau tien khac 0, ko duyet nua
    					{
     						for(k=0;k<n;k++)	//xet tu tren xuong duoi
     							{
      								float t=a[k][i];
      								a[k][i]=a[k][j];
      								a[k][j]=t;
     							}	//doi cho cot i va cot j cho nhau
     							dem++;
								kt++;
     							break;	//neu gap phan tu khac khong, ngay lap tuc thoat khoi vong lap
    					}
   				}
   				if(kt==0) return 0;
  			}
  			
  		// neu phan tu duong cheo khac khong
  		b[i]=a[i][i];	//gan b[i] bang phan tu duong cheo thu i
  				for(j=0;j<n;j++) a[i][j]/=b[i];	//chia tat ca phan tu tai hang i cho phan tu duong cheo => a[i][i]=1
  			for(int t=i+1;t<n;t++)
  				{
   					h=a[t][i];	//tai cot i dang xet, cho h roi tu dong tiep theo den het dong n
   					for(k=0;k<n;k++) a[t][k]=a[t][k]-h*a[i][k];	//tai dong dang xet, cho chay tu dau dong ben trai
   					//den cuoi dong ben phai, giam di 1 luong a[t][i]*a[i][k]
  				}
 		}	//bien doi ma tran ve dang bac thang
	// tai phan tu duong cheo cuoi cung ben phai
 	b[n-1]=a[n-1][n-1];
 	
 	for(i=0;i<n;i++) kq*=b[i];
/*	if(dem%2==0) return kq;
	return -kq;*/	//hoan doi 2 hang/cot cho nhau thi dinh thuc dao dau
 	return kq;
}
 
int main(){
	cin>>DINH;
	dinh = DINH * 2;	//dinh = 4, DINH = 2;
	//input a[1000][1000]
	//cap phat dong ma tran A
	A = new int*[dinh+1];
	for (int i = 0; i < dinh+1; i += 1)
		A[i] = new int[dinh+1];
    //Mac dinh tat ca = 0
	for(int i=1;i<=dinh;i++){
		for(int j=1;j<=dinh;j++){
			A[i][j] = 0;
		}
	}
	A[1][1] = 2;
	A[2][2] = 2;
	A[dinh-1][dinh-1] = 2;
	A[dinh][dinh] = 2;
	for(int i=3;i<=dinh-2;i++){
		A[i][i] = 3;
	}
	//
	for(int i=2;i<=dinh-1;i++){
		//chuyen ve dang ma tran
		if(i%2==0){	//i chan
			A[i][i-1] = -1;
			A[i-1][i] = -1;
			A[i][i+2] = -1;
			A[i+2][i] = -1;
		}
		else{	//i le
			A[i][i-2] = -1;
			A[i-2][i] = -1;
			A[i][i+1] = -1;
			A[i+1][i] = -1;
		}
	}
	//
//	for(int i=1;i<=dinh;i++){
//		for(int j=1;j<=dinh;j++){
//			cout<<A[i][j]<<"		";
//		}
//		cout<<"\n";
//	}
	//
	float** phuDaiSo;
	int dinhPDS = dinh-1;
	phuDaiSo = new float*[dinhPDS];
	for (int i = 0; i < dinhPDS; i += 1)
		phuDaiSo[i] = new float[dinhPDS];
	//
	for(int i=0;i<dinhPDS;i++){
		for(int j=0;j<dinhPDS;j++){
			phuDaiSo[i][j] = A[i+2][j+2];
		}
	}
	//
//	for(int i=0;i<dinhPDS;i++){
//		for(int j=0;j<dinhPDS;j++){
//			cout<<phuDaiSo[i][j]<<"		";
//		}
//		cout<<"\n";
//	}
	//tinh det cua ma tran phu dai so
	long long Q = det(phuDaiSo,dinhPDS);
	while(Q-1000000007 >= 0){
		Q-=1000000007;
	}
	cout<<Q;;
	return 0;
}
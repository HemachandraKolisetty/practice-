//Search in Matrix
#include<iostream>

using namespace std;

bool find(int a[][30],int n,int m,int x){
	int i=0,j=m-1;
	while(i<n && j>=0){
		if(a[i][j]<x) ++i;
		else if((a[i][j]>x)) --j;
		else return true;
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		int a[n][30];
		for(int j=0;j<n;j++) 
			for(int k=0;k<m;k++)
				cin>>a[j][k];
		int x;cin>>x;
		cout<<find(a,n,m,x)<<endl;
	}


}
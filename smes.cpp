#include <iostream>

using namespace std;

void merge(int a[],int b[],int n,int p[]){
	int c=0,i=0,j=0;
	while(i<n && j<n){
		if(a[i]<=b[j]){
			p[c++]=a[i];
			i++;
		}
		else{
			p[c++]=b[j];
			j++;
		}
	}
	if(i==n) for(;j<n;j++) p[c++]=b[j];
	if(j==n) for(;i<n;i++) p[c++]=a[i];
}


int main(){
	int t; cin>>t;
	for(int i=0;i<t;i++){
		int n; cin>>n;
		int a[n],b[n];
		for(int j=0;j<n;j++) cin>>a[j];
		for(int j=0;j<n;j++) cin>>b[j];
		int p[2*n];
		merge(a,b,n,p);
		cout<<p[n-1]+p[n]<<endl;
	}
}
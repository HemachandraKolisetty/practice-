#include<iostream>

using namespace std;

void print(int a[],int n){
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
}

void sort(int a[],int n){  //using counting sort since the range is {0,1,2}
	int c[3],out[n];
	for(int i=0;i<3;i++) c[i]=0;
	for(int i=0;i<n;i++) ++c[a[i]];
	for(int i=1;i<3;i++) c[i]+=c[i-1];
	for(int i=0;i<n;i++){
		out[c[a[i]]-1]=a[i];
		--c[a[i]];
	}
	for(int i=0;i<n;i++) a[i]=out[i];
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[n];
		for(int j=0;j<n;j++) cin>>a[j];
		sort(a,n);
		print(a,n);
	}
}
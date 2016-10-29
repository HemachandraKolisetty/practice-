#include<iostream>

using namespace std;

void print(int a[],int n){
	for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
}

bool find(int a[],int n,int x){
	int i=0,j=n-1,sum;
	while(i<n && j>=0){
		sum=a[i]+a[j];
		if(sum==x) return true;
		else if(x>sum) i++;
		else if(x<sum) j--;
	}
	return false;
}


void merge(int p[],int psize,int q[],int qsize,int a[]){
	int pi=0,qi=0,ai=0; //pi-pindex
	while(pi<psize && qi<qsize){
		if(p[pi]>=q[qi]) a[ai++]= q[qi++];
		else a[ai++]=p[pi++];
	}
	if(pi==psize){
		while(qi<qsize) a[ai++]=q[qi++];
	}
	else if(qi==qsize){
		while(pi<psize) a[ai++]=p[pi++];
	}
}


void mergesort(int a[],int n){
	if(n<2) return;
	else {
		int m =n/2;
		int p[m],q[n-m];
		for(int i=0;i<m;i++)
			p[i]=a[i];
		for(int i=m;i<n;i++)
			q[i-m]=a[i];
		mergesort(p,m);
		mergesort(q,n-m);
		merge(p,m,q,n-m,a);
	}
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int j=0;j<n;j++) cin>>a[j];
		mergesort(a,n);
		//print(a,n);
		if(find(a,n,x)) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}
}
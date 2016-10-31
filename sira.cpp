#include<iostream>

using namespace std;

int search(int a[],int start,int end,int k){
	if(start==end){
		if(a[start]==k) return start;
		else return -1;
	}
	else{
		int size=end-start+1;
		int m=size/2+start;
		if(a[m]>k) return search(a,start,m-1,k);
		else if(a[m]<k) return search(a,m,end,k);	
		else return m;
	}	
}

int findPivot(int a[],int n){
	int p;
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1]){
			p=i;
			break;
		} 
		else continue;
	}
	return p;
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,k;
		cin>>n;
		int a[n];
		for(int j=0;j<n;j++) cin>>a[j];
		cin>>k;
		int pivot=findPivot(a,n);
		if(a[n-1]>=k) cout<<search(a,pivot,n-1,k)<<endl;
		else cout<<search(a,0,pivot-1,k)<<endl;
	}
}
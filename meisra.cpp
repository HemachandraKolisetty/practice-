//Minimum element in sorted and rotated array
#include<iostream>

using namespace std;

int findMin(int a[],int start,int end){
	if(start==end) return a[start];
	else{
		int m=(start+end)/2;
		if(start==m) return a[m]>a[m+1]?a[m+1]:a[m];
		else if(a[start]<a[m]){
			if(a[m]<a[end]) return a[start];
			if(a[m]>a[m+1]) return a[m+1];
			findMin(a,m+1,end);
		}
		else if(a[start]>a[m]){
			if(m-start==1) return a[m];
			findMin(a,start,m);
		}
	}	
}


int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[n];
		for(int j=0;j<n;j++) cin>>a[j];
		cout<<findMin(a,0,n-1)<<endl;
	}
}
#include<iostream>

using namespace std;

void majel(int a[],int n){
	int c[101]={0},out[n];
	for(int i=0;i<n;i++) c[a[i]]++;
	for(int i=0;i<101;i++){
		if(c[i]>n/2){
			cout<<i<<endl;
			break;
		}
		else if(i==100) cout<<"NO Majority Element"<<endl;
	}
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[n];
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		majel(a,n);
	}
}
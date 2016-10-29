#include<iostream>

using namespace std;

bool findPair(int a[],int n,int x){
	bool binMap[1000]={0};
	int temp;
	for(int i=0;i<n;i++){
		temp = x-a[i];
		if(temp>=0) if(binMap[temp]==1) return true;
		binMap[a[i]]=1;
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		if(findPair(a,n,x)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}

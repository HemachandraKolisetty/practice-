//Subarray with a given sum
#include<iostream>

using namespace std;

bool find(int a[],int n,int x,int p[]){
	int sum=0,start=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(sum>x){
			while(sum>x){
				sum-=a[start];
				start++;
			}
		}
		if(sum==x){
			p[0]=start;
			p[1] =i;
			return true;
		} 
	}
	return false;
}



int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int j=0;j<n;j++) cin>>a[j];
		int p[2];
		if(find(a,n,x,p)) cout<<*p+1<<" "<<*(p+1)+1<<endl;
		else cout<<-1<<endl;
	}	
}
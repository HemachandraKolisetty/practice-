#include <iostream>

using namespace std;

int main(){
	int t; cin>>t;
	for(int i=0;i<t;i++){
		int n; cin>>n;
		int t=0;
		long int sum=0;
		while(n-2*t>=0){
			long int prod=1;
			for(int j=0;j<t;j++){
				prod*=n-t-j;
				prod/=j+1;
			}
			sum+=prod;
			t++;
		}
		cout<<sum<<endl;
	}
}
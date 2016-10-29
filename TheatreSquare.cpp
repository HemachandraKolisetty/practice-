#include<iostream>

using namespace std;

int main(){
	long long n,m,a;
	cin>>n>>m>>a;
	if(n/a*a!=n){
		if(m/a*a!=m) cout<<(n/a+1)*(m/a+1);
		else cout<<(n/a+1)*(m/a);
	}
	else{
		if(m/a*a!=m) cout<<(n/a)*(m/a+1);
		else cout<<(n/a)*(m/a);
	}
}
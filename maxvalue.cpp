#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t; cin>>t;
	for(int i=0;i<t;i++){
		int n;cin>>n;
		int a[n];
		for(int j=0;j<n;j++){
			cin>>a[j];
			a[j]-=j;
		}
		int *min=min_element(a,a+n); 
		int *max=max_element(a,a+n);
		cout<<*max-*min<<endl;
	}
}
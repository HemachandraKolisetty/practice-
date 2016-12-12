#include <iostream>
#include <string>

using namespace std;

int main(){
	int N,Q; cin>>N>>Q;
	vector<int> a[N];
	int lastAns=0;
	for(int i=0;i<N;i++) a[i]="";
	for(int i=0;i<Q;i++){
		int k,x,y; cin>>k>>x>>y;
		int temp=(x^lastAns);
		int index=temp%N;
		if(k==1) a[index].append(to_string(y));
		else if(k==2){
			int size=a[index].length();
			lastAns=y%size;
			cout<<lastAns<<endl;
		}
	}
	for(int i=0;i<N;i++) cout<<a[i]<<" ";
	cout<<endl;
}
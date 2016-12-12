#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;cin>>t;
	for(int i=0;i<t;i++){
		int n;cin>>n;
		int x=n;
		vector<int> b;
		while(x>26){
			int t=x%26;
			if(t>0){
				b.push_back(t);
				x/=26;
			}
			else{
				b.push_back(26);
				x=x/26-1;
			}
		}
		b.push_back(x);
		for(int j=b.size()-1;j>=0;j--){
			char temp=b[j]+64;
			cout<<temp;
		}
		cout<<endl;
	}
}
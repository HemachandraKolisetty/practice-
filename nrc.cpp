//Non repeating char
#include<iostream>
#include<string>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int a[26]={0};
		for(int j=0;j<n;j++) a[s[j]-97]++;
		int count=0;
		for(int j=0;j<n;j++){
			if(a[s[j]-97]==1) {cout<<s[j]<<endl; break;}
			else count++;
		}
		if(count==n) cout<<-1<<endl;
	}
}
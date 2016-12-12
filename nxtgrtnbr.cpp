#include <iostream>
#include <string>

using namespace std;

int find_min_index(int a[],int size,int index){
	int min=a[index],i,j,k=index;
	for(i=index+1;i<size;i++){
		if(min<a[i]){
			min=a[i];
			k=i;
			break;
		}
	}	
	for(j=i+1;j<size;j++){
		if(min>a[j] && a[j]>a[index]){
			min=a[j];
			k=j;
		}
	}
	return k;
}

void find_nxtgrtnbr(int a[],int size,int p[]){
	int i,j;
	for(i=size-1;i>0;i--) if(a[i]>a[i-1]) break;
	if(i==0){
		cout<<"not possible"<<endl;
		return;
	} 
	for(j=0;j<i-1;j++) cout<<a[j];
	int index=find_min_index(a,size,i-1);
	cout<<a[index];
	for(j=size-1;j>=i-1 ;j--){
		if(a[i-1]>a[j] && j!=index) cout<<a[j];
		else{
			cout<<a[i-1];
			break;
		}
	}
	if(j!=i-2){
		for(;j>=i ;j--) if(j!=index) cout<<a[j];
	}
	cout<<endl;
}


int main(){
	int t; cin>>t;
	for(int i=0;i<t;i++){
		string n; cin>>n;
		int size=n.length();
		int a[size];
		for(int j=0;j<size;j++) a[j]=n[j]-'0';
		int p[size];
		find_nxtgrtnbr(a,size,p);
	}
}
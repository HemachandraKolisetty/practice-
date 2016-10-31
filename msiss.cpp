//Max sum increasing subsequence
#include<iostream>

using namespace std;

int max(int a[],int n){
	int max=a[0];
	for(int i=1;i<n;i++){
		if(max<a[i]) max=a[i];
	}
	return max;
}

int findMinIndex(int a[],int n,int curr_index,int sum[]){
	if(curr_index==0) return 0;
	else{
		int count=0,maxmin,count2=0;
		for(int i=curr_index-1;i>=0;i--){
			if(a[i]<a[curr_index] && count2==0){
				maxmin=i;
				count2++;
			}
			else if(a[i]<a[curr_index]){
				if(sum[i]>sum[maxmin]) maxmin=i;
			}
			else count++;
		}
		if(count==curr_index) return curr_index;
		else return maxmin;
	}
}

int findMaxsum(int a[],int n){
	int sum[n];
	for(int i=0;i<n;i++) sum[i]=0;
	for(int i=0;i<n;i++){
		sum[i]=sum[findMinIndex(a,n,i,sum)]+a[i];
	}
	return max(sum,n);
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[n];
		for(int j=0;j<n;j++) cin>>a[j];
		cout<<findMaxsum(a,n)<<endl;
	}



}
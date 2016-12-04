#include <iostream>

using namespace std;

int partition(int a[],int start,int end){
	int pivot=start,i=start,j=start+1;
	for(;j<=end;j++){
		if(a[j]<=a[pivot]){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i],a[pivot]);
	return i;
}

void quicksort(int a[],int start, int end){
	if(end>start){
		int pivot=partition(a,start,end);
		quicksort(a,start,pivot);
		quicksort(a,pivot+1,end);
	}
}

int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
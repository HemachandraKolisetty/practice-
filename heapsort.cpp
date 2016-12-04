#include <iostream>

using namespace std;

void max_heapify(int a[],int n,int i){
   int largest=i,l=2*i,r=2*i+1;
   if(l<n && a[l]>a[largest]) largest=l;
   if(r<n && a[r]>a[largest]) largest=r;
   if(largest!=i){
      swap(a[i],a[largest]);
      max_heapify(a,n,largest);
   }
}


void heapsort(int a[],int n){
   for(int i=n/2-1;i>=0;i--) max_heapify(a,n,i);
   for(int i=n-1;i>=0;i--){
      swap(a[0],a[i]);
      max_heapify(a,i,0);
   }
}

int main(){
   int n; cin>>n;
   int a[n];
   for(int i=0;i<n;i++) cin>>a[i];
   heapsort(a,n);
   for(int i=0;i<n;i++) cout<<a[i]<<" ";
   cout<<endl;
}
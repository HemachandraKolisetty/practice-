#include<stdio.h>
#include<stdlib.h>
int find_subarray(int A[],int n,int t)
{
	int i,j=1,k;
	for(i=1;i<=n;i++){	
		if(t>0)	t-=A[i];
		if(t<0){
			t+=A[j];
			j++;
		}
		if(t==0){
			printf("Subarray found \n");
			for(k=j;k<=i;k++)
			printf("%d ",A[k]);
			return;
		}	
	}
	if(t!=0) printf("no such subarray exists\n");
}
int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	int A[n+1],i;
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	find_subarray(A,n,t);
	printf("\n");
}
	

#include<stdio.h>
#include<stdlib.h>
struct node{
	int key;
	struct node *lc;
	struct node *rc;
};
typedef struct node node;
node *T;
void preorder(node *X)
{
	if(X!=NULL)
	{
		printf("%d ",X->key);
		preorder(X->lc);
		preorder(X->rc);
	}
}
void inorder(node *X)
{
	if(X!=NULL)
		{
			inorder(X->lc);
			printf("%d ",X->key);			
			inorder(X->rc);
		}
}
void Insert(int x)
{
	node *y,*curr,*temp;
	y=NULL;
	curr=(node*)malloc(sizeof(node));
	curr->key=x;
	curr->lc=NULL;
	curr->rc=NULL;
	temp=T;
	while(temp!=NULL)
	{
		y=temp;
		if(x<temp->key)
			temp=temp->lc;
		else if (x>temp->key)
			temp=temp->rc;
		else
			return;
	}
	if(y==NULL)
		T=curr;
	else if(x<y->key)
		y->lc=curr;
	else if(x>y->key)
		y->rc=curr;
	
}
int search1(int x)
{
	node *temp;
	int t;
	temp=T;
	t=temp->key;
	while(temp!=NULL)
	{
		if(x<=temp->key)
		{
			t=temp->key;
			temp=temp->lc;
		}
		else if(x>=temp->key)
			temp=temp->rc;
	}
	return t;
}
int search2(int y)
{
	node *temp;
	int t;
	temp=T;
	t=temp->key;
	while(temp!=NULL)
	{
		if(y>=temp->key)
		{
			t=temp->key;
			temp=temp->rc;
		}
		else if(y<=temp->key)
			temp=temp->lc;
	}
	return t;
}
int lca(int p,int q,node* temp)
{
	if(temp->key>p && temp->key>q)
	{
		temp=temp->lc;
		lca(p,q,temp);
	}
	else if(temp->key<q && temp->key<p)
	{
		temp=temp->rc;
		lca(p,q,temp);
	}
	else
		return temp->key;
}
void printrange(int x,int y,node* temp)
{
	if(temp!=NULL)
	{
	
		if(temp->key>x && temp->key<y)
		{
			printrange(x,y,temp->lc);
			printf("%d ",temp->key);
			printrange(x,y,temp->rc);
		}
		else if(temp->key>x && temp->key>y)
		{
			temp=temp->lc;
			printrange(x,y,temp);
		}
		else if(temp->key<x && temp->key<y)
		{
			temp=temp->rc;
			printrange(x,y,temp);
		}
	}
}
int main()
{
	T=(node*)malloc(sizeof(node));
	T=NULL;
	int n,i,k,x,y;
	printf("n = ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		Insert(k);
	}
	printf("preorder : ");
	preorder(T);
	printf("\ninorder : ");
	inorder(T);
	printf("\nx = ");
	scanf("%d",&x);
	printf("y = ");
	scanf("%d",&y);
	printf("search1(%d) : %d\n",x,search1(x));
	printf("search2(%d) : %d\n",y,search2(y));
	printf("lca(%d,%d) : %d\n",search1(x),search2(y),lca(x,y,T));
	printf("Values in T between %d and %d are : ",x,y);
	printrange(x,y,T);
	printf("\n");
}

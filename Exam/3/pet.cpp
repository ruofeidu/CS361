#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define inf 2147483647
#define base 1000000

struct node
{
	int key,aux,cnt;
	node *left,*right;
};
typedef node *Tnode;
Tnode root,nilpoint;

inline void LeftRotate(Tnode &root)
{
	Tnode t=root->left;
	root->left=t->right;
	t->right=root;
	root=t;
}

inline void RightRotate(Tnode &root)
{
	Tnode t=root->right;
	root->right=t->left;
	t->left=root;
	root=t;
}

inline void Insert(Tnode &root,int x)
{
	if (root==nilpoint)
	{
		root=new(node);
		root->cnt=1;
		root->key=x;
		root->aux=((rand()<<15)+rand());
		root->left=root->right=nilpoint;
		return;
	}
	
	if (root->key==x) ++root->cnt;
	else if (x<root->key)
	{
		Insert(root->left,x);
		if (root->left->aux<root->aux) LeftRotate(root);
	}else
	{
		Insert(root->right,x);
		if (root->right->aux<root->aux) RightRotate(root);
	}
}

inline void Delete(Tnode &root,int x)
{
	if (root->key==x)
	{
		if (root->cnt>1)
		{
			--root->cnt;
			return;
		}
		if (root->left==nilpoint && root->right==nilpoint)
		{
			root=nilpoint;
			return;
		}
		if (root->left->aux<root->right->aux)
		{
			LeftRotate(root);
			Delete(root->right,x);
		}else
		{
			RightRotate(root);
			Delete(root->left,x);
		}
		return;
	}
	if (x<root->key) Delete(root->left,x);
	else Delete(root->right,x);
}

inline int FindMin(Tnode &root,int x)
{
	if (root==nilpoint) return -1;
	
	int t=-1;
	if (x>=root->key)
	{
		t=root->key;
		int t1=FindMin(root->right,x);
		if (t1!=-1) t=t1;
		return t;
	}
	return FindMin(root->left,x);
}

inline int FindMax(Tnode &root,int x)
{
	if (root==nilpoint) return -1;
	
	int t=-1;
	if (x<=root->key)
	{
		t=root->key;
		int t1=FindMax(root->left,x);
		if (t1!=-1) t=t1;
		return t;
	}
	return FindMax(root->right,x);
}

int main()
{
	freopen("pet.in","r",stdin);
	freopen("pet.out","w",stdout);
	
	nilpoint=new(node);
	nilpoint->left=nilpoint->right=nilpoint;
	nilpoint->aux=inf;
	nilpoint->cnt=0;
	root=nilpoint;
	
	int n;
	scanf("%d",&n);
	int cur=0,tot=0;
	long long ans=0;
	for (int i=0;i<n;++i)
	{
		int a,x;
		scanf("%d%d",&a,&x);
		if (!tot || a==cur)
		{
			++tot;
			cur=a;
			Insert(root,x);
		}else
		{
			--tot;
			int key1=FindMin(root,x),key2=FindMax(root,x),key;
			if (key1==-1) key=key2;
			else if (key2==-1) key=key1;
			else if (x-key1<=key2-x) key=key1;
			else key=key2;
			if (key<=x) ans+=x-key;
			else ans+=key-x;
//			printf("%d\n",key);
			Delete(root,key);
		}
	}
	
	printf("%d\n",(int)(ans%base));
	
//	printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
	
	return 0;
}

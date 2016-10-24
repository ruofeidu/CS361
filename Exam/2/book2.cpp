#include <cstdio>
#include <ctime>
#include <cstring>
#define maxn 1005

bool mark[maxn],adj[maxn][maxn];
int a[maxn],heap[maxn],n,m,hz,Ans[maxn];

inline void swap(int &a,int &b)
{
	int t=a;a=b;b=t;
}

inline void up(int x)
{
	for (int y=x/2;y;y=x/2)
	{
		if (a[heap[y]]<a[heap[x]]) swap(heap[x],heap[y]);
		else break;
		x=y;
	}
}

inline void sink(int x)
{
	for (int y=x*2;y<=hz;y=x*2)
	{
		if (y<hz && a[heap[y+1]]>a[heap[y]]) ++y;
		if (a[heap[y]]>a[heap[x]]) swap(heap[x],heap[y]);
		else break;
		x=y;
	}
}

int main()
{
	freopen("book2.in","r",stdin);
	freopen("book2.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	{
		mark[i]=false;
		scanf("%d",&a[i]);
	}
	
	for (int i=1;i<=m;++i)
	{
		int id;
		scanf("%d",&id);
		mark[id]=true;
		heap[++hz]=id;
		up(hz);
	}
	
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			int x;
			scanf("%d",&x);
			adj[i][j]=(x>0);
		}
	
	int len=0;
	while (hz)
	{
		int u=heap[1];
		Ans[len++]=u;
		heap[1]=heap[hz--];
		if (hz) sink(1);
		
		for (int v=1;v<=n;++v)
		if (adj[u][v] && !mark[v])
		{
			mark[v]=true;
			heap[++hz]=v;
			up(hz);
		}
	}
	
//	printf("%d\n",len);
	for (int i=0;i<len;++i)
		printf("%d\n",Ans[i]);
		
//	printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
	
	return 0;
}

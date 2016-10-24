#include <cstdio>
#include <cstring>
#define maxn 1005

int adj[maxn][maxn],n,m,q[maxn];
bool vis[maxn];

int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for (int i=0;i<m;++i)
	{
		scanf("%d",&q[i]);
		vis[q[i]]=true;
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			scanf("%d",&adj[i][j]);
	
	int h,tail;
	for (h=0,tail=m;h<tail;++h)
	{
		int u=q[h];
		for (int v=1;v<=n;++v)
		if (adj[u][v]==1 && !vis[v])
		{
			vis[v]=true;
			q[tail++]=v;
		}
	}
	printf("%d\n",q[tail-1]);
	
	return 0;
}

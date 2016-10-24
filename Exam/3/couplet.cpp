#include <cstdio>
#include <ctime>
#include <cstring>
#define maxn 100005
#define base 1000007

int head[base+5],vtx[maxn],next[maxn],tot,n,m,L,t[100];
char s[100];

inline int get()
{
	scanf("%s",s);
	t[0]=0;
	for (int j=1;j<L;++j)
	if (s[j]==s[j-1]) t[j]=t[j-1];
	else t[j]=t[j-1]^1;
	int x=0;
	for (int j=0;j<L;++j)
		x=x*2+t[j];
	return x;
}

inline void Insert(int x)
{
	int y=x%base;
	for (int p=head[y];p;p=next[p])
	if (vtx[p]==x) return;
	
	vtx[++tot]=x;
	next[tot]=head[y];
	head[y]=tot;
}

inline bool Find(int x)
{
	int y=x%base;
	for (int p=head[y];p;p=next[p])
	if (vtx[p]==x) return true;
	return false;
}

int main()
{
	freopen("couplet.in","r",stdin);
	freopen("couplet.out","w",stdout);
	
	memset(head,0,sizeof(head));
	tot=0;
	scanf("%d%d%d",&n,&L,&m);
	for (int i=0;i<n;++i)
	{
		int x=get();
		Insert(x);
	}
	
	for (int i=0;i<m;++i)
	{
		int x=get();
		if (Find(x)) puts("Yes");
		else puts("No");
	}
	
//	printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
	
	return 0;
}

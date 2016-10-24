#include <cstdio>
#include <cstring>
#define maxn 2005

char Tree[maxn],Mid[maxn],Pre[maxn];
bool mark[maxn];
int n,p;

inline void solve(int num,int l,int r)
{
	if (l>r) return;
	Tree[num]=Pre[p];
	mark[num]=true;
	for (int i=l;i<=r;++i)
	if (Mid[i]==Pre[p])
	{
		++p;
		solve(num*2,l,i-1);
		solve(num*2+1,i+1,r);
	}
}

int main()
{
	freopen("Tree.in","r",stdin);
	freopen("Tree.out","w",stdout);
	
	scanf("%s%s",Pre,Mid);
	
	n=strlen(Pre);
	p=0;
	memset(mark,false,sizeof(mark));
	solve(1,0,n-1);
	
	int last=2000;
	while (!mark[last]) --last;
	for (int i=1;i<=last;++i)
	{
		if (mark[i]) printf("%c",Tree[i]);
		else printf("NULL");
		if (i==last) puts("");
		else printf(" ");
	}
	
	return 0;
}

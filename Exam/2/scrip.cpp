#include <cstdio>
#include <cstring>
#include <ctime>
#define maxn 500005

int n,m,a[maxn];

int main()
{
	freopen("scrip.in","r",stdin);
	freopen("scrip.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	
	for (int i=0;i<m;++i)
	{
		int x,l,r,Ans=-1,ansp;
		scanf("%d",&x);
		
		l=0,r=n+1;
		while (l+1<r)
		{
			int mid=(l+r)>>1;
			if (a[mid]<=x) l=mid;
			else r=mid;
		}
		if (l!=0)
		{
			if (Ans==-1 || Ans>x-a[l])
			{
				Ans=x-a[l];
				ansp=a[l];
			}
		}
		
		l=0,r=n+1;
		while (l+1<r)
		{
			int mid=(l+r)>>1;
			if (a[mid]>=x) r=mid;
			else l=mid;
		}
		if (r!=n+1)
		{
			if (Ans==-1 || Ans>a[r]-x)
			{
				Ans=a[r]-x;
				ansp=a[r];
			}
		}
		
		printf("%d\n",ansp);
	}
	
//	printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
	
	return 0;
}

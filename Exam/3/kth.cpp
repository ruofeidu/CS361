#include <cstdio>
#include <cstring>
#include <ctime>
#define maxn 1234568

int a[maxn],n,k;

inline void Kth(int l,int r,int k)
{
	int i=l,j=r,mid=a[(i+j)/2];
	while (i<=j)
	{
		while (a[i]<mid) ++i;
		while (a[j]>mid) --j;
		if (i<=j)
		{
			int t=a[i];a[i]=a[j];a[j]=t;
			++i;--j;
		}
	}
	if (k>=i && k<=r) Kth(i,r,k);
	if (k>=l && k<=j) Kth(l,j,k);
}

int main()
{
	freopen("kth.in","r",stdin);
	freopen("kth.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	
	--k;
	Kth(0,n-1,k);
	
	printf("%d\n",a[k]);
	
//	printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
	
	return 0;
}

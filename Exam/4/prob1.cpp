
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define maxn 200000
int n,m;
int weight[maxn+10];
struct edge
{
 int x,y,last;
};
struct element
{
 int id,weight;
};
bool operator <(const element&x,const element&y)
{
 if (x.weight!=y.weight) return x.weight<y.weight;
 else return x.id<y.id;
}
int first[maxn+10];
edge e[maxn+10];
int degree[maxn+10];
int output[maxn+10];
int numEdge=0;
int heapSize=0;
element heap[maxn+10];
void add_edge(int x,int y)
{
	edge n;
	n.x=x;n.y=y;n.last=first[x];
	numEdge++;
	first[x]=numEdge;
	e[numEdge]=n;
}
void up(int m)
{
 int p=m,q=m/2;
 if (q<=0) return;
 while (heap[p]<heap[q])
  {
   element t=heap[p];heap[p]=heap[q];heap[q]=t;
   p=q;q=p/2;
   if (q<=0) return;
  }
}
void down(int m)
 {
  int p=m,q=m*2;
  if (q>heapSize) return;
  if ((q+1<=heapSize) && (heap[q+1]<heap[q])) q++;
  while (heap[q]<heap[p])
   {
   element t=heap[p];heap[p]=heap[q];heap[q]=t;
   p=q;q=p*2;
   if (q>heapSize) return;
   if ((q+1<=heapSize) && (heap[q+1]<heap[q])) q++;
   }
 }
int main()
{	
     freopen("quarrel.in", "r", stdin);
    freopen("quarrel.out", "w", stdout);
 scanf("%d %d",&n,&m);
 for (int i=1;i<=n;i++)
 scanf("%d",&weight[i]);
 memset(degree,0,sizeof(degree));
 memset(first,0,sizeof(first));
 for (int i=0;i<m;i++)
  {
	int x,y;
 	scanf("%d%d",&x,&y);
	add_edge(x,y);
	degree[y]++;
  }
 for (int i=1;i<=n;i++)
 {
	if (degree[i]==0)	
	{
	 heapSize++;
	 element t;
	 t.id=i;t.weight=weight[i];
	 heap[heapSize]=t;
	 up(heapSize);
	}
 }
 for (int i=1;i<=n;i++)
  {
     if (heapSize == 0)
          {
            printf("Impossible\n");
            exit(0);
          }

     element t=heap[1];
     heap[1]=heap[heapSize];
     heapSize--;
     down(1);
     output[i]=t.id;
     int p=first[t.id];
     while (p!=0)
      {

	degree[e[p].y]--;
	if (degree[e[p].y]==0)
	 {
  	  heapSize++;
 	 element u;
	 u.id=e[p].y;u.weight=weight[i];
	 heap[heapSize]=u;
	 up(heapSize);
	 }	
 	p=e[p].last;
      }
  }
 for (int i = 1; i <= n; i++)
      printf("%d\n", output[i]);
 return 0;
}

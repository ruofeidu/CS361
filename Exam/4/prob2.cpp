#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define maxn 300000
struct edge
  {
    int x, y, last, last2;
  };

struct element
{
    int x, p;
    int phase;
};
int numEdge=0,n=0,m;
int first[maxn+10],first2[maxn+10];
bool available[maxn+10];
edge e[maxn+10];
int degree[maxn+10];
element s[maxn+10];
int output[maxn+10];
  void add_edge(int x,int y)
{
	edge n;
	n.x=x;n.y=y;n.last=first[x];
	n.last2=first2[y];
	numEdge++;
	first[x]=numEdge;
	first2[y]=numEdge;
	e[numEdge]=n;
}
int main()
{
    freopen("please.in", "r", stdin);
    freopen("please.out", "w", stdout);
    scanf("%d", &m);
    memset(first,0,sizeof(first));
    memset(degree,0,sizeof(degree));
    for (int i = 1; i <= m; i++)
      {
        int x, y;
        scanf("%d%d", &x, &y);
        n = max(max(n, x), y);
        add_edge(x,y);
        degree[x]++;degree[y]++;
      }
    int start=-1;
    int oddCount=0;
    for (int i=0;i<n;i++)
     {
       if (start==-1) start=i;
       if (degree[i]%2==1)
        {
         oddCount++;
         start=i;
        }
     }
     if ((oddCount!=0)&&(oddCount!=2)) 
      {
        printf("Impossible");
        return 0;
      }
      memset(available,true,sizeof(available));
     int top=1;
     int ansCount=0;
     s[top].x=start;
     s[top].phase=1;
     s[top].p=first[start];
     while (top!=0)
      {
           element current=s[top];
           while (current.p!=0)
            {
             if (available[current.p])
              {
               available[current.p]=false;
               element next;
               if (current.phase==1)
                {
                 next.x=e[current.p].y;
                 next.p=first[e[current.p].y];
                 next.phase=1;
                 s[top]=current;
                 top++;
                 s[top]=next;
                 goto abc;
                }
                else
                {
                 next.x=e[current.p].x;
                 next.p=first[e[current.p].x];
                 next.phase=1;
                 s[top]=current;
                 top++;
                 s[top]=next;
                 goto abc;
                }
              }
              if (current.phase==1) current.p=e[current.p].last;
               else current.p=e[current.p].last2;
            }
          if (current.phase==1)
           {
            current.phase=2;
            current.p=first2[current.x];
            s[top]=current;
           }
           else
           {ansCount++;
            output[ansCount]=current.x;
            top--;
           }
abc:;            
      }
       if (m+1!=ansCount)  
        {
         printf("Impossible");
         return 0;
        }
       for (int i=1;i<=ansCount;i++)
              printf("%d\n", output[i]); 
        
}

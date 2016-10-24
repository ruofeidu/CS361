#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define maxn 3000000
int father[maxn + 10];
int count[maxn + 10];
int d;
int find_root(int m)
 {
  if (father[m]==0) return m;
  int t=find_root(father[m]);
  father[m]=t;
  return t;   
 }
int main()
{
    freopen("propose.in", "r", stdin);
    freopen("propose.out", "w", stdout);
    scanf("%d\n", &d);
    memset(father, 0, sizeof(father));
    for (int i = 1; i <= maxn; i++)
      count[i] = 1;
    while (d>0)
     {
      d--;
      char c;
      int x, y;
      scanf("%c %d %d\n",&c,&x,&y);
      int p = find_root(x);
      int q = find_root(y);
      if (c=='A')
       {
        if (p!=q)
         {
          father[p]=q;
          count[q]+=count[p];
          }
         
       }
       else
       {
           if (p==q) printf("%d\n",count[p]);
            else printf("They are not friends.\n");
       }
      }  
     return 0;
}

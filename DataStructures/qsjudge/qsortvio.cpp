#include <iostream>
using namespace std; 
const int MAXN = 1000000; 
int n, k;
int a[MAXN];  
bool cmp(int a,int b){ return a>b; }
int main(){
    freopen("qs.in","r",stdin);
    freopen("qsvio.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; ++i ) scanf("%d",&a[i]);
    sort(a,a+n,cmp);
    printf("%d\n",a[k-1]);
    return 0; 
}

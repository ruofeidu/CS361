#include <iostream>
using namespace std; 
const int MAXN = 1000000; 
int a[MAXN];
int n,k,ans; 

int findk(int l, int r){
    int value,i,j;
    if (l==r) return l; 
    int p=rand()%(r-l)+l; 
    value=a[p];
    swap(a[p],a[l]);
    i=l; j=r;
    while (i<j){
        while (i<j&&a[j]<value) --j;
        if (i<j) {a[i]=a[j]; ++i; } else break; 
        while (i<j&&a[i]>value) ++i; 
        if (i<j) {a[j]=a[i]; --j; } else break; 
    }
    a[i]=value; 
    if (k<i) return findk(l,i-1); else 
    if (k>i) return findk(i+1,r); else return i; 
}

int main(){
    freopen("qs.in","r",stdin);
    freopen("qs.out","w",stdout); 
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; ++i ) scanf("%d",&a[i]);
    printf("%d\n",a[findk(1,n)]);
    return 0; 
}

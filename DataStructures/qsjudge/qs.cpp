#include <iostream>
using namespace std; 
const int MAXN = 100000; 
int n, k;
int a[MAXN]; 

int qs(int l, int r){
    if (l==r) return l; 
    int p = rand()%(r-l)+l; 
    int value = a[p];
    int i = l, j = r; 
    swap(a[p],a[l]);
    while (i<j){
        while (i<j&&a[j]<value) --j; 
        if (i<j){a[i]=a[j]; ++i; } else break; 
        while (i<j&&a[i]>value) ++i; 
        if (i<j){ a[j]=a[i]; --j; } else break; 
    }
    a[i]=value; 
    if (k<i) return qs(l,i-1); else
    if (k>i) return qs(i+1,r); else return i; 
}

int main(){
    srand(time(0)^141592653);
    freopen("qs.in","r",stdin);
    freopen("qs.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; ++i ) scanf("%d",&a[i]);
    printf("%d\n",a[qs(1,n)]);
    return 0; 
}   
    

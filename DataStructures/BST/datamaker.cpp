#include <fstream>
using namespace std; 
ofstream fout("BST.in");
const int MAXN = 100000; 

int a[MAXN]; 
bool g[MAXN]; 

int main(){    
    freopen("BST.in","w",stdout);
    srand(time(0)^141592653);
    int n = (rand()<<10) % MAXN + 1, k = n / 2;
    int total = n; 
    
    memset(g, false, sizeof(g)); 
    for ( int i = 0; i < n; ++i ) a[i] = i; 
    for ( int i = 0; i < n / 2; ++i ) { g[rand() % n] = true; --total; } 
    //printf("%d %d\n",n,n+n-total+n+n);
   
    printf("%d %d\n",n,n+n-total+n);
        
    for ( int i = 0; i < n; ++i ) printf("I %d\n",a[i]); 
    for ( int i = 0; i < n; ++i ) if (g[i]) printf("D %d\n",a[i]); 
    //for ( int i = 0; i < n; ++i ) printf("F %d\n", rand() % (n-n/3)+1); 
    for ( int i = 0; i < n; ++i ) printf("B %d\n",a[i]);
    //if (rand()%2==0) printf("A %d\n", a[i]); else 
    return 0;     
}

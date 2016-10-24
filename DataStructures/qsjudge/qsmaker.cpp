#include <iostream>
using namespace std; 

const int MAXN = 100000; 
int n,k;

int main(){
    srand(time(0)^141592653); 
    freopen("qs.in","w",stdout);
    n = (rand()<<4)%MAXN;
    k = rand()%n; 
    printf("%d %d\n",n,k);
    for (int i = 0; i < n; ++i ) printf("%d ",rand());
    return 0; 
}

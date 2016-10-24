#include <fstream>
using namespace std; 
ifstream fin("data.in");
ofstream fout("datavio.out");
const int MAXN = 100000; 
int a[MAXN]; 

bool cmp(int a,int b){ return a>b;}

int main(){
    int n, k; 
    fin >> n >> k; 
    
    for ( int i = 0; i < n; ++i ) fin >> a[i]; 
    sort( a, a+n, cmp);
    fout << a[k-1] << endl; 

    return 0;    
}

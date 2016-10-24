#include <fstream>
using namespace std;
ifstream fin("data.in");
ofstream fout("data.out");
const int MAXN = 1000001; 

int a[MAXN],ans = -1,n,k;

int findk(int l, int r){
    int p, value, i, j; 
    if (l==r) return l; 
    p = rand() % (r-l)+l; 
    value = a[p];
    swap(a[p],a[l]);
    i = l; j = r; 
    while (i < j ){
        while ( i < j && a[j] < value ) --j; 
        if (i<j) { a[i] = a[j]; ++i; } else break; 
        while ( i < j && a[i] > value ) ++i; 
        if (i<j) { a[j] = a[i]; --j; } else break; 
    }
    a[i] = value; 
    if ( k>i ) return findk(i+1,r); 
    if ( k<i ) return findk(l,i-1);
    return i; 
}

int main()
{
    srand(time(0)^141592653);
	fin >> n >> k; 
	for ( int i = 1; i <= n; ++i ) fin >> a[i]; 
	ans = findk(1,n);
	fout << a[ans] << endl; 
	return 0; 
}


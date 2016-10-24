#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
ifstream fin("hash.in");
ofstream fout("hash_vio.out");

const int MAXN = 100000; 

int n,m = 0; 
char c; 
string s,a[MAXN]; 
bool g[MAXN]; 

int main(){
    fin >> n; 
    memset(g, true, sizeof(g) ); 
    for ( int i = 0; i < n; ++i ){
        fin >> c >> s;
        switch (c) {
            case 'I': a[m++] = s; break;
            case 'D': for ( int j = 0; j < m; ++j ) if (g[j] && a[j]==s) {g[j]=false; break; } break;
            case 'F': bool ok = false; 
                        for ( int j = 0; j < m; ++j ) if (g[j] && a[j]==s) { fout << 1 << endl; ok = true; break; } 
                        if (!ok) fout << 0 << endl; break; 
        }
    }           
            
    return 0;  
}

#include <fstream>
using namespace std; 
ofstream fout("data.in");
const int MAXN = 100000; 
const int MAXK = 10000; 

int main(){    
    srand(time(0)^141592653);
    int n = rand() % MAXN + 1, k = rand() % n + 1;
    fout << n << ' ' << k << endl; 
    for ( int i = 0; i < n; ++i ){
        fout << rand() % MAXN + 1 << ' ' << endl; 
    }
    
    return 0;     
}

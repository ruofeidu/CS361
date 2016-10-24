#include <fstream>
#include <string>
#include <cmath>
using namespace std;
ofstream fout("hash.in"); 

const int MAXN = 1000; 
const int MAXL = 30; 

string s[MAXN]; 

int main(){
    srand(time(0)^141592653); 
    int n = rand() % MAXN; 
    fout << 3*n << endl;  
    for ( int i = 0; i < n; ++i ){
        fout << "I ";
        s[i] = "";
        char c;    
        for ( int j = 0; j < MAXL; ++j ){
            c = char('A'+rand()%26); 
            s[i] = s[i] + c;
            fout << c;
        }
        fout << endl; 
    }
    
    for ( int i = 0; i < 2*n; ++i )
    if (rand()%2==0) fout << "D " << s[rand()%n] << endl; else
                     fout << "F " << s[rand()%n] << endl; 

    return 0;  
}

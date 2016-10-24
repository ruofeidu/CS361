#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
ifstream fin("hash.in");
ofstream fout("hash.out"); 

class hash{
public:
    static const int HMOD = 500000; 
    
    class node{
    public:
        string data; 
        node *next; 
        node(string x = ""):data(x),next(0){}
    }; 
    node *h[HMOD];

public:
    int make(string x){
        int ans = 0; 
        for ( int i = 0; i < x.size(); ++i )
            ans = ( ans + int(x[i]) - int('A')) % HMOD;
        return ans; 
    }
            
    bool find(string x){
        int index = make(x); 
        node *v = h[index];
        while (v && v->data != x) v = v->next; 
        if (v) return true; else return false; 
    }
    
    void ins(string x){
        int index = make(x); 
        node *v = new node(x);  
        v->next = h[index];
        h[index] = v;    
    }       
    
    void del(string x){
        int index = make(x); 
        node *v = h[index]; 
        if (!v) return;
        if (v->data == x) { h[index] = v->next; return; }
        while (v->next && v->next->data != x) v = v->next; 
        if (!v->next) return; 
        v->next = v->next->next;      
    }
};

hash h;
int n; 
char c; 
string x; 

int main(){
    fin >> n; 
    for ( int i = 0; i < n; ++i ) {
        fin >> c >> x; 
        switch (c){
            case 'I': h.ins(x); break;  
            case 'D': h.del(x); break; 
            case 'F': fout << h.find(x) << endl; break;  
        }
    }
    return 0;  
}

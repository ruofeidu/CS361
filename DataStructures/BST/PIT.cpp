#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
ifstream fin("BST.in");
ofstream fout("pit.out");

class PIT{
    static const int B = 0; 
    static const int E = 300000; 

public:
    class Node{
    public:
        int s, k;      
        Node *l, *r;
    public:
        Node( int ss = 0, int kk = 0 ):l(NULL),r(NULL){ s = ss; k = kk; }    
    };    
    
    Node *root;
    
public:
    PIT(){ root = new Node(); }
    
    void Ins( Node *t, int b, int e, int k ){
        if ( b == e ) if ( t->k != k ) { t->k = k; t->s = 0; } else; else
        if ( k <= ((b+e)>>1) ) {
            if ( t->l == NULL ) t->l = new Node();
            Ins( t->l, b, (b+e)>>1, k );
        } else {
            if ( t->r == NULL ) t->r = new Node();
            Ins( t->r, ((b+e)>>1)+1, e, k );
        }
        ++t->s;
    }
    void Ins( int k ){ Ins(root, B, E, k ); }
    
    void Del( Node *t, int b, int e, int k ){
        if ( t == NULL ) return;
        --t->s;  if ( b == e ) return;
        if ( k <= (b+e)>>1 ) Del( t->l, b, (b+e)>>1, k ); else Del( t->r, ((b+e)>>1)+1, e, k );
    }
    void Del( int k ){ Del(root, B, E, k ); }
    
    int Rfs( Node *t, int b, int e, int k ){
        if ( b == e ) return( t->k );
        int ls = t->l == NULL ? 0 : t->l->s; 
        if ( k <= ls ) return Rfs( t->l, b, (b+e)>>1, k ); 
            else return Rfs( t->r, ((b+e)>>1)+1, e, k - ls );
    }
    int Rfs( int k ){ if (k>=1 && k <= root->s) return Rfs( root, B, E, k ); else return -1; }
    
    bool Find( Node *t, int b, int e, int k ){
        if ( t == NULL ) return false; 
        if ( b == e && t->s > 0 ) return true;  
        if ( k <= (b+e)>>1 ) return Find(t->l, b, (b+e)>>1, k ); else return Find(t->r, ((b+e)>>1)+1, e, k );
    }
    bool Find( int k ){ return Find(root, B, E, k ); }
    
    int GetRank( Node *t, int b, int e, int k ){
        if ( t == NULL ) return 0; 
        if ( b == e ) if ( t->s >0 )return 1; else return 0;  
        int ls = t->l == NULL ? 0 : t->l->s; 
        if ( k <= (b+e)>>1 ) return GetRank(t->l, b, (b+e)>>1, k); else
                             return ls + GetRank(t->r, ((b+e)>>1)+1, e, k );
    }
    int GetRank( int k ) { return GetRank(root, B, E, k ); }
};

    int n, m, k;
    char c; 
    PIT pit;

int main(){
    fin >> n >> m;  
    for ( int i = 0; i < m; ++i ) {
        fin >> c >> k; 
        switch (c){
            case 'I': pit.Ins(k); break;
            case 'D': pit.Del(k); break;  
            case 'F': fout << pit.Rfs(k) << endl; break; 
            case 'B': fout << pit.Find(k) << endl; break; 
            case 'A': fout << pit.GetRank(k) << endl; break; 
        } 
    }  
    return 0;  
}

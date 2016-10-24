#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std; 
ifstream fin("BST.in");
ofstream fout("treap.out");

const int INF = 2000000000; 
class treap{
public:
    class node{
    public:
        node *l,*r; 
        int x,y,c;
        node(int xx):x(xx),c(0),l(0),r(0){ y=(rand()<<15+rand())%INF; } 
    };
    node *root, *null; 
    
    void lr(node *&p){
        node *q = p->l; p->l = q->r; q->r = p; update(p); update(q); p = q; 
    }
    
    void rr(node *&p){
        node *q = p->r; p->r = q->l; q->l = p; update(p); update(q); p = q; 
    }
    
    void update(node *&p){
        if (p!=null) p->c = p->l->c + p->r->c + 1; 
    }
    
    void ins(node *&p, int x){
        if (p==null) { p = new node(x); p->l = p->r = null; p->c = 1; } else
        if (x<p->x){ ins(p->l,x); if (p->l->y < p->y) lr(p); } 
              else { ins(p->r,x); if (p->r->y < p->y) rr(p); }
        update(p);
    }
    
    void del(node *&p){
        if (p->l==null && p->r ==null){
            delete p; p = null; return; 
        }
        if (p->l->y < p->r->y){ lr(p); del(p->r); } else { rr(p); del(p->l); }
        update(p);
    } 
    
    void del(node *&p, int x){
        if (p==null) return; 
        if (x>p->x) del(p->r,x); else
        if (x<p->x) del(p->l,x); else del(p);
        if (p!=null) update(p);
    }
    
    int rfs(node *&p, int k){
        if (k<=p->l->c) return rfs(p->l,k); else
        if (k==p->l->c+1) return p->x; else return rfs(p->r,k-p->l->c-1);
    }
    
    int getrank(int x){
        node *p = root; int ans = 0;
        while (p!=null) { 
            if (x<p->x) p = p->l; else {
                if (x==p->x && x==p->l->x) {p=p->l; continue; }
                ans += p->l->c + 1; 
                if (x==p->x) break; 
                p = p->r; 
            }
        }
        return ans; 
    }
    
    bool find(node *&p, int x){
        if (p==null) return false; 
        if (x==p->x) return true; 
        if (x<p->x) return find(p->l,x); else return find(p->r, x); 
    }
public:
    treap(){ null = new node(0); null->y = INF; null->l = null->r = null; root = null; }
    void ins(int x){ ins(root,x); }
    void del(int x){ del(root,x); }
    bool find(int x){ return find(root,x); }
    int rfs(int k){ if (k>=1 && k<=root->c) return rfs(root,k); else return -1; }
};

int n, m, k;
char c;  
treap t; 

int main(){
    fin >> n >> m;  
    for ( int i = 0; i < m; ++i ) {
        fin >> c >> k; 
        switch (c){
            case 'I': t.ins(k); break;
            case 'D': t.del(k); break;  
            //case 'F': fout << t.rfs(k) << endl; break; 
            case 'B': fout << t.find(k) << endl; break; 
            //case 'A': fout << t.getrank(k) << endl; break; 
        } 
    }  
    return 0;  
}

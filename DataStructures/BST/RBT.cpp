//作者：杜若飞 
//学号：5090109228 
//题目：128
//时间：2010.5.21
//说明：红黑树的递归实现 V1.1 为了方便调试，采用文件输入输出，从BST.in读入数据,从RBT.out输出数据
//数据格式：N,M N为结点最多个数，无用。M为命令个数
//命令格式：I x为插入x ；D x为删除x； B x为查找x是否存在 
//思路：非递归改递归就是如果该在左子树插入，就递归访问左子树，否则递归访问右子树。 
//其他：各个操作的平均时间复杂度为O(log N)，用treap对拍AC，不考虑重复结点 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <typename T> 
class Node{ 
public: 
    Node() : red(false), exist(false), left(NULL), right(NULL), parent(NULL){} 
    Node(T &t) : data(t), red(true), exist(true), left(NULL), right(NULL), parent(NULL){} 
    Node<T>* maximum(); 
    Node<T>* minimum(); 
    Node<T>* successor(); 
    Node<T>* predecessor();  
    bool isExist() { return this ->exist; } 
    bool isNULL() { return !this ->exist; } 
    bool getColor() { return this ->red; } 
    bool isRed(){ return this ->red; } 
    bool isBlack() { return !this ->red; } 
    void setColor(bool c) { this ->red = c; } 
    void setRed() { this ->red = true; } 
    void setBlack() { this ->red = false; } 
    
    T data; 
    bool red; 
    bool exist; 
    Node<T>* left; 
    Node<T>* right; 
    Node<T>* parent; 
};


template <typename T, typename E> 
class RBTree{ 
public: 
    RBTree() : root(NULL){} 
    ~RBTree(); 
    bool Insert(T &);           //插入 
    bool Delete(T &, E);        //删除 
    bool Find(T);               //查找 
    void traverse();            //遍历 
    T get_head(){ return root ->data;}  //取得头结点 
private: 
    //删除 
    void delete_tree(Node<T>*); 
    bool delete_node(T&, Node<T>*);
    //插入
    bool insert_node(T&, Node<T>*); 
    //旋转 
    void left_rotate(Node<T>*); 
    void right_rotate(Node<T>*); 
    // 维护 
    void insert_fixup(Node<T>*); 
    void delete_fixup(Node<T>*); 
    // 遍历，方便别人做简答题:-) 
    void traverse(Node<T>*); 
    Node<T>* root; 
};

template <typename T> 
Node<T>* Node<T>::maximum(){ 
    Node<T>* x = this; 
    while(x ->right ->isExist()) 
        x = x ->right; 
    return x; 
}

template <typename T> 
Node<T>* Node<T>::minimum(){ 
    Node<T>* x = this; 
    while(x ->left ->isExist()) 
        x = x ->left; 
    return x; 
}

template <typename T> 
Node<T>* Node<T>::successor(){ 
    Node<T>* y; 
    Node<T>* x; 
    if(this ->right ->isExist()) 
        return this ->right ->minimum(); 
    x = this; 
    y = x ->parent; 
    while(y != NULL && x == y ->right){ 
        x = y; 
        y = x ->parent; 
    } 
    return y; 
}

template <typename T> 
Node<T>* Node<T>::predecessor(){ 
    Node<T>* y; 
    Node<T>* x; 
    if(this ->left ->isExist()) 
        return this ->left ->maximum(); 
    x = this; 
    y = x ->parent; 
    while(y != NULL && x == y ->left){ 
        x = y; 
        y = x ->parent; 
    } 
    return y; 
} 

template <typename T, typename E> 
RBTree<T, E>::~RBTree(){ 
    this ->delete_tree(this ->root); 
}

template <typename T, typename E> 
void RBTree<T, E>::delete_tree(Node<T>* p){ 
    if(p){ 
        if(p ->left) 
            this ->delete_tree(p ->left); 
        if(p ->right) 
            this ->delete_tree(p ->right); 
        delete p; 
    } 
}

template <typename T, typename E> 
bool RBTree<T, E>::Insert(T &t){ 
    if(this ->root == NULL || this ->root ->isNULL()){ 
        if(this ->root) 
            delete this ->root; 
        this ->root = new Node<T>(t); 
        this ->root ->left = new Node<T>(); 
        this ->root ->left ->parent = this ->root; 
        this ->root ->right = new Node<T>(); 
        this ->root ->right ->parent = this ->root; 
        this ->root ->setBlack(); 
        return true; 
    } 
    return insert_node( t, root); 
}

template <typename T, typename E> 
bool RBTree<T, E>::insert_node( T &t, Node<T>* p){ 
    if(t == p ->data) return false; 
    if(t < p ->data){ 
        if(p ->left ->isNULL()){ 
            delete p ->left; 
            p->left = new Node<T>(t); 
            p->left ->parent = p; 
            p->left ->left = new Node<T>(); 
            p->left ->left ->parent = p ->left; 
            p->left ->right = new Node<T>(); 
            p->left ->right ->parent = p ->left; 
            this ->insert_fixup(p ->left); 
            return true; 
        } 
        else 
            return insert_node( t, p->left ); 
    } 
    else{ 
        if(p ->right ->isNULL()){ 
            delete p ->right; 
            p ->right = new Node<T>(t); 
            p ->right ->parent = p; 
            p ->right ->left = new Node<T>(); 
            p ->right ->left ->parent = p ->left; 
            p ->right ->right = new Node<T>(); 
            p ->right ->right ->parent = p ->left; 
            this ->insert_fixup(p ->right); 
            return true; 
        } 
        else 
            return insert_node( t, p->right ); 
    } 
    
    return false; 
}

template <typename T, typename E> 
bool RBTree<T, E>::Find(T t){
    Node<T>* p = root; 
    while ( p != NULL && p->data != t )
        if ( p->data > t ) p = p->left; else p = p->right;
         
    if ( p == NULL ) return false; else return true; 
}

template <typename T, typename E> 
void RBTree<T, E>::insert_fixup(Node<T>* z){ 
    Node<T>* y;

    while(z ->parent && z ->parent ->isRed()){ 
        if(z ->parent == z ->parent ->parent ->left){ 
            y = z ->parent ->parent ->right; 
            if(y ->isRed()){ 
                //情况1 
                z ->parent ->setBlack(); 
                y ->setBlack(); 
                z ->parent ->parent ->setRed(); 
                z = z ->parent ->parent; 
            } 
            else{  
                if(z == z ->parent ->right){ 
                    // 情况2
                    z = z ->parent; 
                    this ->left_rotate(z); 
                } 
                // 情况 3 
                z ->parent ->setBlack(); 
                z ->parent ->parent ->setRed(); 
                this ->right_rotate(z ->parent ->parent); 
            } 
        } 
        else{ 
            y = z ->parent ->parent ->left; 
            if(y ->isRed()){ 
                // 情况 4 
                z ->parent ->setBlack(); 
                y ->setBlack(); 
                z ->parent ->parent ->setRed(); 
                z = z ->parent ->parent; 
            } 
            else{  
                if(z == z ->parent ->left){ 
                    // 情况5
                    z = z ->parent; 
                    this ->right_rotate(z); 
                } 
                // 情况6
                z ->parent ->setBlack(); 
                z ->parent ->parent ->setRed(); 
                this ->left_rotate(z ->parent ->parent); 
            } 
        } 
    } 
    this ->root ->setBlack(); 
} 

//删除并维护 
template <typename T, typename E> 
bool RBTree<T, E>::Delete(T &t, E e){ 
    Node<T>* p = this ->root; 
    while(p ->isExist()){ 
        if(p ->data == e) 
            return this ->delete_node(t, p); 
        else if(e < p ->data) 
            p = p ->left; 
        else 
            p = p ->right; 
    } 
    return false; 
}

template <typename T, typename E> 
bool RBTree<T, E>::delete_node(T& t, Node<T>* z){ 
    Node<T>* y; 
    Node<T>* x;

    if(z ->left ->isNULL() || z ->right ->isNULL()) 
        y = z; 
    else 
        y = z ->successor(); 
    if(y ->left ->isExist()){ 
        x = y ->left; 
        if(y ->right ->isNULL()) 
            delete y ->right; 
    } 
    else{ 
        x = y ->right; 
        if(y ->left ->isNULL()) 
            delete y ->left; 
    } 
    x ->parent = y ->parent; 
    if(y ->parent == NULL) 
        this ->root = x; 
    else if(y == y ->parent ->left) 
        y ->parent ->left = x; 
    else 
        y ->parent ->right = x; 
    if(y != z){ 
        T temp = z ->data; 
        z ->data = y ->data; 
        y ->data = temp; 
    } 
    if(y ->isBlack()) 
        this ->delete_fixup(x); 
    t = y ->data;

    delete y;

    return true; 
}

template <typename T, typename E> 
void RBTree<T, E>::delete_fixup(Node<T>* x){ 
    Node<T>* w; 
    while(x != this ->root && x ->isBlack()){ 
        if(x == x ->parent ->left){ 
            w = x ->parent ->right; 
            if(w ->isRed()){ 
                //情况1  
                w ->setBlack(); 
                x ->parent ->setRed(); 
                this ->left_rotate(x ->parent); 
                w = x ->parent ->right; 
            } 
            if(w ->left ->isBlack() && w ->right ->isBlack()){ 
                //情况2 
                w ->setRed(); 
                x = x ->parent; 
            } 
            else{ 
                if(w ->right ->isBlack()){ 
                    //情况3
                    w ->left ->setBlack(); 
                    w ->setRed(); 
                    this ->right_rotate(w); 
                    w = x ->parent ->right; 
                } 
                //情况4
                w ->setColor(x ->parent ->getColor()); 
                x ->parent ->setBlack(); 
                w ->right ->setBlack(); 
                this ->left_rotate(x ->parent); 
                x = this ->root; 
            } 
        } 
        else{ 
            w = x ->parent ->left; 
            if(w ->isRed()){ 
                //情况5
                w ->setBlack(); 
                x ->parent ->setRed(); 
                this ->right_rotate(x ->parent); 
                w = x ->parent ->left; 
            } 
            if(w ->left ->isBlack() && w ->right ->isBlack()){ 
                //情况6
                w ->setRed(); 
                x = x ->parent; 
            } 
            else{  
                if(w ->left ->isBlack()){ 
                    //情况7
                    w ->right ->setBlack(); 
                    w ->setRed(); 
                    this ->left_rotate(w); 
                    w = x ->parent ->left; 
                } 
                //情况8
                w ->setColor(x ->parent ->getColor()); 
                x ->parent ->setBlack(); 
                w ->left ->setBlack(); 
                this ->right_rotate(x ->parent); 
                x = this ->root; 
            } 
        } 
    } 
    x ->setBlack(); 
}

//旋转 
template <typename T, typename E> 
void RBTree<T, E>::left_rotate(Node<T>* x){ 
    Node<T>* y = x ->right; 
    x ->right = y ->left; 
    if (y ->left) y ->left ->parent = x; 
    y ->parent = x ->parent; 
    if(x ->parent == NULL) 
        this ->root = y; 
    else{ 
        if(x == x ->parent ->left) 
            x ->parent ->left = y; 
        else 
            x ->parent ->right = y; 
    } 
    //关系调整 
    y ->left = x; 
    x ->parent = y; 
}

template <typename T, typename E> 
void RBTree<T, E>::right_rotate(Node<T>* x){ 
    Node<T>* y = x ->left; 
    x ->left = y ->right; 
    if(y ->right) y ->right ->parent = x; 
    y ->parent = x ->parent; 
    if(x ->parent == NULL) 
        this ->root = y; 
    else{ 
        if(x == x ->parent ->left) 
            x ->parent ->left = y; 
        else 
            x ->parent ->right = y; 
    }  
    //关系调整
    y ->right = x; 
    x ->parent = y; 
}

//遍历红黑树 
template <typename T, typename E> 
void RBTree<T, E>::traverse(){ 
    traverse(root); 
}

template <typename T, typename E> 
void RBTree<T, E>::traverse(Node<T>* p){ 
    cout << p->data << " "; 
    cout << p->data << "LEFT";
    if (p->left != NULL) traverse(p->left); else cout << "NULL "; 
    cout << p->data << "RIGHT";
    if (p->right != NULL ) traverse(p->right); else cout << "NULL "; 
}

int m,k,n,x,y=0; 
char s[2];   
RBTree<int, int> t; 

int main(void){ 
    freopen("BST.in","r",stdin); 
    freopen("RBT.out","w",stdout);
    scanf("%d%d",&m,&n);
    for (int i = 0; i < n; ++i ){
        scanf("%s%d",&s,&x);
        switch (s[0]) { 
            case 'I': t.Insert(x); break; 
            case 'D': t.Delete(y,x); break; 
            case 'B': printf("%d\n",t.Find(x)); break; 
        }
    }
    return 0;
}

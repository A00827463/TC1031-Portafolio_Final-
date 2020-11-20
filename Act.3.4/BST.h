#ifndef BST_h
#define BST_h
#include "Nodo.h"
#include <queue>
#include <stack>

class BST{
private:
    Node * root;
    int num;
    int cont;
    void destruye( Node * r);
    int sizeHelper(Node * r);
    void top(Node* r);
public:
    BST();
    ~BST();
    void add(int data, long ip, string s);
    int size();
    void printTop(int num);
};

BST::BST(){
    root = nullptr;
}

BST:: ~BST(){
    destruye(root);
}
// Complejidad O(n)
void BST:: destruye(Node *r){
    if(r != nullptr){
        destruye(r->getLeft());
        destruye(r->getRight());
        delete r;
    }
}

// complejidad O(altura del arbol)
void BST:: add(int data,long ip, string s){
    Node * curr = root;
    Node * father = nullptr;
    while (curr != nullptr) {
        father = curr;
        //curr = (curr->getData() > data)? curr->getLeft() : curr->getRight();
        if(curr -> getData() > data){
            curr = curr->getLeft();
        }
        else if (curr->getData() < data){
            curr = curr->getRight();
        }
        else{
            curr = (curr -> getIp() > ip) ? curr->getRight() : curr->getLeft();
        }
    }
    if(father == nullptr){
        root = new Node(data, ip,s);
    }
    else{
        if(father->getData() > data){
            father->setLeft(new Node(data, ip,s));
        }
        else if (father->getData() < data){
            father->setRight(new Node(data,ip,s));
        }
        else{
            // if(father-> getIp() > ip){
            //     father->setRight(new Node(data,ip,s));
            // }
            // else{
            //     father->setLeft(new Node(data,ip,s));
            // }
            (father->getIp() > ip) ? father->setRight(new Node(data,ip,s)) :
            father->setLeft(new Node(data,ip,s));
        }
    }
}

// complejidad O(altura del arbol)
int BST:: sizeHelper(Node * r){
    if(r == nullptr){
        return 0;
    }
    return 1 + sizeHelper(r->getLeft()) + sizeHelper(r->getRight());
}
// complejidad O(altura del arbol)
int BST :: size(){
    return sizeHelper(root);
}



// Complejidad(num)
void BST::top(Node* r){
    if(r != nullptr){
        top(r->getRight());
        if (num>0){
            cout << "[" <<cont<<"] "<< r->getData() << " " << r->getStIp() << endl;
            num--;
            cont++;
        }
        top(r->getLeft());
    }
}
// Complejidad(num)
void BST::printTop(int num){
    this-> cont = 1;
    this->num = num;
    top(root);
}

#endif /* BST_h */

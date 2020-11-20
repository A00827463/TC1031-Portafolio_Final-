#ifndef Nodo_h
#define Nodo_h
class Node{
private: int data;
    string stIp;
    long ip;
    Node * left;
    Node * right;
public:
    Node(int data, long ip, string stIp);
    Node(int data, long ip, string stIp, Node * left, Node * right);
    int getData();
    void setData(int data);
    long getIp();
    void setIp(long ip);
    void setStIp(string s);
    string getStIp();
    Node * getLeft();
    Node * getRight();
    void setRight(Node * right);
    void setLeft(Node * left);
    
};

Node::Node(int data, long ip, string stIp){
    left = nullptr;
    right = nullptr;
    this-> data = data;
    this-> ip = ip;
    this->stIp = stIp;
}

Node::Node(int data, long ip,string stIp, Node * left, Node * right){
    this->data = data;
    this->left = left;
    this->right = right;
    this-> ip = ip;
    this->stIp = stIp;
}

int Node:: getData(){
    return data;
}
void Node::setData(int data){
    this->data = data;
}
long Node:: getIp(){
    return ip;
}
void Node:: setIp(long ip){
    this -> ip = ip;
}
Node * Node::  getLeft(){
    return left;
};
Node * Node::  getRight(){
    return right;;
}
void Node:: setRight(Node * right){
    this->right = right;
}
void Node:: setLeft(Node * left){
    this-> left = left;
}

void Node:: setStIp(string s){
    stIp = s;
}
string Node:: getStIp(){
    return stIp;
}

#endif /* Nodo_h */

#ifndef Node_h
#define Node_h
struct Dato{
    int  dia; 
    long ipKey;
    string mes, hora, ip,mensaje;
};


class Node {
private:
    Dato data;
    Node * next;
    Node * prev;
    
public:
    Node(Dato data);
    Node(Dato data, Node  *prev, Node * next);
    Dato getData();
    Node * getNext();
    Node * getPrev();
    void setData(Dato data);
    void setNext( Node  *next);
    void setPrev( Node  *prev);
    // void setKey(long key);
    
};


Node::Node(Dato data){
    this -> data = data;
    this -> next = nullptr;
    this -> prev = nullptr;
}


Node::Node(Dato data,Node * prev, Node  * next){
    this-> data = data;
    this-> next = next;
    this-> prev = prev;
}


Dato Node:: getData(){
    return data;
}

Node* Node:: getNext(){
    return next;
}

Node* Node :: getPrev(){
    return prev;
}

void Node :: setData(Dato data){
    this->data = data;
}


void Node :: setNext(Node *next){
    this -> next = next;
}

void Node:: setPrev(Node *prev){
    this -> prev = prev;
}
#endif /* Node_h */

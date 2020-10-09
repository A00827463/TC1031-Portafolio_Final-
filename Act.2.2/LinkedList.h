//sebastian Rodriguez A00827463
#include "Node.h"

template <class T>
class LinkedList
{
public:
    LinkedList();
    bool create(T data, int pos);
    void addFirst(T data);        // Check
    void addLast(T data);          // Check
    int read(T data);              // Check
    bool update(T data1, T data2); // Check
    void deleteFirst();           // Check
    void deleteLast();            // Check
    bool del(T data);            // Check
    void print();                 // Check
private:
    Node<T> *head;
    int size;
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    size = 0;
}

//Complejidad O(n)
template<class T>
bool LinkedList<T>::create(T data, int pos){
    if (pos>size || pos<0){
        return false;
    }
    if (pos == 0){
        addFirst(data);
    }
    else if (pos == size){
        addLast(data);
    }
    else{
        Node<T> *curr = head;
        for (int i =1; i<pos; i++){
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
    }
    return true;
}

//Complejidad O(1)
template <class T>
void LinkedList<T>::addFirst(T data)
{
    head = new Node<T>(data, head);
    size++;
}

//Complejidad O(n)
template <class T>
void LinkedList<T>::addLast(T data)
{
    if (size == 0)
    {
        addFirst(data);
    }
    else
    {
        Node<T> *curr = head;
        while (curr->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}

//Complejidad O(1)// Complejidad O(n)
template <class T>
int LinkedList<T>::read(T data)
{
    Node<T> *curr = head;
    int cont = 0;
    for (int i = 1; i <= size; i++)
    {
        if (data == curr->getData()){
            return i-1;
        }
        curr = curr->getNext(); 

    }
    return -1;
    //return curr->getData();
}

// Comlejidad O(n)
template <class T>
bool LinkedList<T>::update(T data1, T data2)
{
    Node<T> *curr = head;
    for (int i = 1; i <= size; i++)
    {
        int cont = 0;
        if(curr->getData() == data1){
            curr->setData(data2);
            cont +=1;
        }
        curr = curr->getNext();
    }

    return true;
}

//Complejidad O(1)
template <class T>
void LinkedList<T>::deleteFirst()
{
    if (head != nullptr)
    {
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}

//Complejidad O(1)
template <class T>
void LinkedList<T>::deleteLast()
{
    if (size <= 1)
    {
        deleteFirst();
    }
    else
    {
        Node<T> *curr = head;
        while (curr->getNext()->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        delete curr->getNext();
        size--;
        curr->setNext(nullptr);
    }
}

// Intento "del" fallido

// //Complejidad O(n)
// template <class T>
// void LinkedList<T>::del(T data)
// {
//     Node<T> *curr = head;
//     for (int i = 1; i<=size, i++){
//         int cont = 0;
//         if (curr->getData() == data && cont == 0)
//         {
//             cont += 1;
//             deleteFirst();
//         }
//         else if (curr->getNext()->getNext() == nullptr && data == curr->getNext()->getData())
//         {
//             deleteLast();

//         }
//         else if (curr->getData() == data)
//         {
//             Node<T> *aux = curr->getData();
//             curr->setNext(aux->getNext());
//             delete aux;
//             size--;
//         }
//         curr = curr->getNext();
//     }
// }

//Complejidad O(n)
template <class T>
bool LinkedList<T>::del(T data)
{
    bool check = false;
    while (head != nullptr && head->getData() == data){
        deleteFirst();
        check = true;
    }
    if (head != nullptr){
        Node<T> *curr = head;
        Node<T> *aux = head->getNext();
        while (aux != nullptr){
            if (aux->getData()==data){
                curr->setNext(aux->getNext());
                delete aux;
                size--;
                check = true;
                aux = curr->getNext();
            }
            else{
                curr = aux;
                aux = aux->getNext();
            }
        }
    }
    return check;
}


//Complejidad O(n)
template <class T>
void LinkedList<T>::print()
{
    Node<T> *curr = head;
    int num = 0;
    cout << "Contenido de la LinkedList" << endl;
    while (curr != nullptr)
    {
        cout << "[" << num << "] - " << curr->getData() << endl;
        curr = curr->getNext();
        num++;
    }
}
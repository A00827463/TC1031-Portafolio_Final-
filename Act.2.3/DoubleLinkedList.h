// Sebastian Rodriguez A00827463
// Lucas Idigoras A00827751

#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h
#include <fstream>
#include "Node.h"
template <class T>
class DoubleLinkedList
{
private:
    int size;
    Node *head;
    Node *tail;
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    bool isEmpty();
    int getSize();
    void addAtFront(Dato data);
    void addAtLast(Dato data);
    void print();
    void bothDirectionPrint();
    void sortBurbuja();
    int busqSec(long data);
    void addFromTo(DoubleLinkedList<Dato> &resultante, int data1, int data2);
    void txt();
};
template <class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    size = 0;
    head = nullptr;
}
// complejidad: O(n)
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    Node *curr = head;
    while (head != nullptr)
    {
        head = head->getNext();
        delete curr;
        curr = head;
    }
}

// Complejidad O(1)
template <class T>
bool DoubleLinkedList<T>::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// complejidad: O(1)
template <class T>
int DoubleLinkedList<T>::getSize()
{
    return size;
}

// Complejidad O(1)
template <class T>
void DoubleLinkedList<T>::addAtFront(Dato data)
{
    head = new Node(data, nullptr, head);
    tail = head;
    size++;
}

// Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::addAtLast(Dato data)
{
    if (size == 0)
    {
        addAtFront(data);
    }
    else
    {
        Node *curr = head;
        while (curr->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node(data, curr, nullptr));
        tail = curr->getNext();
        size++;
    }
}

//complejidaa: O(n)
template <class T>
void DoubleLinkedList<T>::print()
{
    Dato x;
    Node *curr = head;
    while (curr != nullptr)
    {
        x = curr->getData();
        cout << x.mes << " " << x.dia << " " << x.hora << " " << x.ip << " " << x.mensaje << endl;
        curr = curr->getNext();
    }
}

// Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::bothDirectionPrint()
{
    Node *temp = head;
    cout << "\nprint de izquierda a derecha usando getNext()\n";
    while (head)
    {
        Dato x = head->getData();
        cout << x.dia << " " << x.mes << endl;
        temp = head;
        head = head->getNext();
    }
    cout << "\nPrint de derecha a izquierda usando getPrevious\n";
    while (temp)
    {
        Dato y = temp->getData();
        cout << y.dia << " " << y.mes << endl;
        temp = temp->getPrev();
    }
}

// Complejidad O(n^2)
template <class T>
void DoubleLinkedList<T>::sortBurbuja()
{
    bool interuptor = true;
    Dato x, y;
    string str= "";
    cout << "\033[2J\033[1;1H";
    for (int i = 0; i < size && interuptor; i++)
    {

        if (i%(size/20) == 0){
            cout<<"Cargando Datos"<<str<<endl;
            cout << "\033[2J\033[1;1H";
            str += "."; 
        }
        Node *curr = head;
        interuptor = false;
        for (int j = 1; j < size - i; j++)
        {
            y = curr->getData();
            x = curr->getNext()->getData();
            if (x.ipKey < y.ipKey)
            {
                curr->setData(x);
                curr->getNext()->setData(y);
                interuptor = true;
            }
            curr = curr->getNext();
        }
    }
}

// Complejidad O(n)
template <class T>
int DoubleLinkedList<T>::busqSec(long data)
{   
    Dato a;
    Node * end = tail;
    a = end->getData();
    if (data < 0 || data >9999999999999999 || data <999999999999999){
        return -1;
    }
    if (a.ipKey < data){
        return size-1;
    }

    Dato x, y, z;
    Node *curr = head;
    x = curr->getData();
    if (x.ipKey >data){
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        x = curr->getData();

        if (i != 0)
        {
            y = curr->getPrev()->getData();
        }
        if (i != size - 1)
        {
            z = curr->getNext()->getData();
        }

        if (x.ipKey == data)
        {
            return i;
        }
        else if (y.ipKey < data && z.ipKey > data){
            return i+1;
        }
        curr = curr->getNext();
    }
    
    return -1;
}

// Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::addFromTo(DoubleLinkedList<Dato> &resultante, int data1, int data2)
{
    Dato x;
    Node *curr = head;
    for (int i = 0; i < data1; i++)
    {
        curr = curr->getNext();
    }
    for (int i = data1; i <= data2; i++)
    {
        x = curr->getData();
        resultante.addAtLast(x);
        curr = curr->getNext();
    }
}

// Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::txt()
{
    ofstream fs;
    fs.open("Resultado.txt");
    Dato x;
    Node *curr = head;
    for (int i = 0; i < size; i++)
    {
        x = curr->getData();
        fs << x.dia << " " << x.mes << " " << x.hora << " " << x.ip << " " << x.mensaje << endl;
        curr = curr->getNext();
    }
}
#endif /* DoubleLinkedList_h */

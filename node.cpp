#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T *data;
    Node<T> *leftChild;
    Node<T> *rightChild;
    Node<T> *parent;

public:
    Node()
    {
        data = nullptr;
        leftChild = nullptr;
        rightChild = nullptr;
        parent = nullptr;
    }

    Node(T *data)
    {
        this->data = data;
        leftChild = nullptr;
        rightChild = nullptr;
        parent = nullptr;
    }
    void set_data(T *newData)
    {
        data = newData;
    }
    void set_left(Node<T> *Lchild)
    {
        leftChild = Lchild;
    }
    void set_right(Node<T> *Rchild)
    {
        rightChild = Rchild;
    }
    void set_parent(Node<T> *par)
    {
        parent = par;
    }

    T* get_data()
    {
        return data;
    }
    Node<T> *get_left()
    {
        return leftChild;
    }
    Node<T> *get_right()
    {
        return rightChild;
    }
    Node<T> *get_parent()
    {
        return parent;
    }
    void print()
    {

        data->print();

    }
};

#include <iostream> 

template <typename T> 
struct Node
{
    Node* prev; 
    T data; 
    Node* next; 
};

template <typename T> 
class DoublyLinkedList
{
    struct Node<T>* head = nullptr; 
    struct Node<T>* trailer = nullptr;
public: 
    DoublyLinkedList()
    {
        head = new Node<T>; 
        trailer = new Node<T>; 
        head->next = trailer; 
        trailer->prev = head; 
    }
    void addFront(const T& element)
    {
        add(head->next, element);
    }
    void insertAfter(Node<T>* p, const T& data)
    {
        add(p->next, data);
    }
    void insertBefore(Node<T>* p, const T& data)
    {
        add(p, data);
    }
    void addBack(const T& element)
    {
        add(trailer, element);
    }
    void removeFront()
    {
        remove(head->next);
    }
    void removeBack()
    {
        remove(trailer->prev);
    }
    void printFoward()
    {
        Node<T>* current = head->next; 
        while(current != trailer)
        {
            std::cout << current->data << " "; 
            current = current->next; 
        }
        std::cout << std::endl;
    }
    void printBack()
    {
        Node<T>* current = trailer->prev; 
        while(current != head)
        {
            std::cout << current->data << " "; 
            current = current->prev; 
        }
        std::cout << std::endl;
    }
    bool empty() {return (head->next == trailer);}
    T front() {return head->next->data;}
    T back() {return trailer->prev->data;}
    Node<T>* getHead() const
    {
        return head;
    }

    Node<T>* getTrailer() const
    {
        return trailer;
    }
protected: 
    void add(Node<T>* v, const T& element)
    {
        Node<T>* tmp = new Node<T>; 
        tmp->data = element; 
        tmp->next = v;
        tmp->prev = v->prev; 
        v->prev->next = tmp; 
        v->prev = tmp; 
    }
    void remove(Node<T>* v)
    {
        Node<T>* previous = v->prev; 
        Node<T>* successor = v->next; 

        previous->next = successor; 
        successor->prev = previous; 
        delete v; 
    }
    
};

int main()
{
    DoublyLinkedList<int> DL;
    DL.addFront(1);
    DL.addFront(2);
    DL.addBack(4); 
    DL.printFoward(); 
    DL.printBack();
    std::cout << "front: " << DL.front() << std::endl; 
    std::cout << "Back: " << DL.back() << std::endl;

    Node<int>* secondNode = DL.getHead()->next->next;
    DL.insertBefore(secondNode, 3);
    DL.insertAfter(secondNode, 10);
    std::cout << "After inserting 3 before the second node:" << std::endl;
    DL.printFoward();
}
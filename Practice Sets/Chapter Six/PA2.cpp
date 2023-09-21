#include <iostream> 
#include <string> 

template <typename T>
struct Node
{
    struct Node* prev; 
    T data; 
    struct Node* next; 
};

template <typename T> 
class DLinkedList
{
    struct Node<T>* head = nullptr; 
public: 
    DLinkedList()
    {
        head = new Node<T>;
        head->prev = nullptr; 
        head->next = nullptr; 
    }
    struct Iterator
    {
        Node<T>* current; 
        Iterator(Node<T>* p)
        {
            current = p; 
        }
        void operator++()
        {
            if(current)
                current = current->next; 
        }
        T& operator*()
        {
            return current->data; 
        }
        bool operator!=(const Iterator& other)
        {
            return current != other.current; 
        }
    };
    Iterator begin()
    {
        return Iterator(head); 
    }
    Iterator end()
    {
        return Iterator(nullptr); 
    }
    void create(T data)
    {
        head->data = data; 
    }
    void insertFront(T data)
    {
        struct Node<T>* tmp = new Node<T>; 
        tmp->prev = nullptr; 
        tmp->data = data; 
        tmp->next = head; // connect the next to head
        head->prev = tmp; // connect the previous to ahve two nodes
        head = tmp; // set it to be first
    }
    void insertBack(T data)
    {
        struct Node<T>* tmp, *current;
        tmp = new Node<T>;
        tmp->prev = nullptr; 
        tmp->data = data; 
        tmp->next = nullptr; 
        current = head; 
        while(current->next != nullptr)
        {
            current = current->next; 
        }
        current->next = tmp; 
        tmp->prev = current; 
    }
    T deleteFirst()
    {
        T x = head->data; 
        struct Node<T>* temp; 
        if(head->next != nullptr)
        {
            temp = head; 
            head = head->next;  
            delete head->prev; //delete previous node
            head->prev = nullptr; 
        }
        return x; 
    }
    T deleteLast()
    {
        T x = head->data; 
        struct Node<T>* current = head; 
        struct Node<T>* temp; 
        while(current->next != nullptr)
        {
            current = current->next; 
        }
        temp = current->prev; 
        temp->next = nullptr; 
        return x; 
    }
    void display()
    {
        std::cout << "List of elements: ";
        struct Node<T>* current = head; 
        while(current != nullptr)
        {
            std::cout << current->data << " "; 
            current = current->next; 
        }
        std::cout << std::endl; 
    }
};

int main(int argc, char const *argv[])
{
    DLinkedList<std::string> list;
    
    list.insertFront("Two"); 
    list.insertBack("Three"); 
    list.insertFront("One"); 
    list.insertBack("Four");

    for(DLinkedList<std::string>::Iterator itr = list.begin(); itr != list.end(); ++itr)
        std::cout << *itr << " "; 
    std::cout << std::endl; 

    list.deleteFirst(); 
    list.deleteLast(); 

    list.insertFront("Noah Rainbow"); 

    DLinkedList<std::string>::Iterator itr2 = list.begin(); 
    ++itr2; 

    for(; itr2 != list.end(); ++itr2)
        std::cout << *itr2 << " "; 
    std::cout << std::endl; 

    return 0;
}

#include <iostream> 

template<typename T> 
struct Node
{
    T data; 
    struct Node* next; 
};

void InsertFront(struct Node<int>* &first, int element)
{
    struct Node<int>* tmp = new Node<int>; 
    tmp->data = element; 
    tmp->next = first; 
    first = tmp; 
}

void InsertPos(struct Node<int>* &first, int index, int x)
{
    Node<int>* temp = new Node<int>; 
    temp->data = x; 

    if(index == 0)
    {
        temp->next = first; 
        first = temp; 
    }
    else 
    {
        Node<int>* current = first; // set a temp node
        for(int i = 0; i < index -1 && current->next != nullptr; ++i) // Move to the position
        {
            current = current->next; // loop to that position
        }
        temp->next = current->next; // connect the temp node to the current node
        current->next = temp; // set the current node equal to the temp 
    }
    
}

void InsertBack(struct Node<int>* &first, int x)
{
    Node<int>* newNode = new Node<int>; 
    newNode->data = x;
    newNode->next = NULL; 
    if(first == nullptr)
        first = newNode; 
    else 
    {
        Node<int>* temp = first; 
        while(temp->next != nullptr)
            temp = temp->next; 
        temp->next = newNode; 
    }
}


int Delete(struct Node<int>* &p, int index, int x)
{
    Node<int>* q = nullptr; 

    if(index == 0)
    {
        Node<int>* tmp = p; 
        q = p; 
        x = tmp->data; 
        p = p->next; // Move to next
        delete tmp; 
        return x; 
    }
    else 
    {
        Node<int>* current = p; 
        for(int i = 0; i < index - 1 && current !=nullptr; ++i)
        {
            q = current; 
            current = current->next; 
        }
        q->next = current->next; 
        x = current->data; 
        delete current; 
        return x; 
    }
    
}

void display(struct Node<int>* p)
{
    Node<int>* current = p; 
    while(current!=nullptr)
    {
        std::cout << current->data << " "; 
        current = current->next; 
    }
    std::cout << std::endl; 
}

int main(int argc, char const *argv[])
{
    Node<int>* first = new Node<int>; 
    first->data = 2; 
    first->next = NULL; 

    InsertFront(first, 100); 
    InsertPos(first, 0, 10);
    InsertPos(first, 1, 20); 
    InsertPos(first, 3, 40);
    InsertBack(first, 200);
    Delete(first, 0, 10); 
    Delete(first, 0, 20);
    display(first); 

    return 0;
}

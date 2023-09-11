#include <iostream> 
#include <stdexcept> 

template <typename T> 
struct Node
{
    T data; 
    struct Node* next; 
};

void insertFront(struct Node<int>* &p, int x)
{
    Node<int>* tmp = new Node<int>; 
    tmp->data = x; // assign the data in the temp Node
    tmp->next = p; // Assign our next linker next to the first node
    p = tmp; // set our first node to our tmp making it first
}

void insertPosition(struct Node<int>* &p, int index, int x)
{
    if(index < 1)
      throw std::out_of_range("Index is out of bounds (less than 1)"); 

    // Create a new temp Node 
    Node<int>* tmp = new Node<int>; 
    tmp->data = x; 

    if(index == 1)
    {
        tmp->next = p; 
        p = tmp; 
    }
    else 
    {
        struct Node<int>* current = p; 

        // setup the loop to the position wanted 
        for(int i = 0; i < index - 1 && current != nullptr; ++i) 
        {
            current = current->next; // loop to that position
        }
        tmp->next = current->next; // attach the tmp node to the current node 
        current->next = tmp; // attach the current node to the tmp node by doing this we create the node in itself
    }
    
}

void InsertBack(struct Node<int>* &p, int x)
{
    Node<int>* tmp = new Node<int>;
    tmp->data = x; 
    tmp->next = nullptr; 
    
    if(p == nullptr)
        p = tmp; // set this into the head
    else 
    {
        Node<int>* current = p; 
        while(current->next != nullptr)
        {
            current = current->next; // all the way at the end of our linked list
        }
        current->next = tmp; // create a node at the end
    }
}

int Delete(struct Node<int>* &p, int index, int x)
{
    Node<int>* q = nullptr; 

    if(index == 1)
    {
        q = p; // moving to the first pointer
        x = p->data; 
        p = p->next; // move to the next first node
        delete q;
        return x; 
    }
    else 
    {
        Node<int>* current = p; 
        for(int i = 0; i < index - 1 && current != nullptr; ++i) // traversing to the position
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
    struct Node<int>* current = p;
    while(current != nullptr) // iterate all of the list 
    {
        std::cout << current->data << " "; 
        current = current->next; 
    }
}

int main(int argc, char* const argv[])
{
    struct Node<int>* head = new Node<int>;  
    head->data = 3; 
    head->next = nullptr; 

    insertFront(head, 20);
    insertPosition(head, 1, 50); 
    insertPosition(head, 2, 20);
    insertPosition(head, 3, 20);
    insertPosition(head, 4, 500);
    InsertBack(head, 540);
    Delete(head, 1, 50); 
    Delete(head, 1, 20);     
    Delete(head, 3, 500); 
    display(head);   
}
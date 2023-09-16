#include <iostream> 

template <typename T>
struct Node
{
    T data; 
    struct Node* next; 
}; 

template <typename T> 
void push(struct Node<int>* &top, T x)
{
    Node<int>* tmp = new Node<int>; 
    tmp->data = x; 
    tmp->next = top; 
    top = tmp; 
}

template<typename T> 
T pop(struct Node<int>* &top)
{
    T x = T(); 
    Node<int>* tmp; 
    if(top == nullptr)
        std::out_of_range("Stack is empty"); 
    else 
    {
        tmp = top; 
        top = top->next; 
        x = tmp->data; 
        delete tmp; 
    }
    return x; 
}

bool isEmpty(struct Node<int>* top) {return top == nullptr;}

void display(struct Node<int>* top)
{
    struct Node<int>* current = top; 
    while(current != nullptr)
    {
        std::cout << current->data << " "; 
        current = current->next; 
    }

}

int main(int argc, char const *argv[])
{
    struct Node<int>* stack = nullptr; // head must be a pointer because this is linked whereas arrays is not necessary
    push(stack, 10); 
    push(stack, 20); 
    pop<int>(stack); 
    display(stack); 
    return 0;
}



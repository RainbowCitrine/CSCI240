#include <iostream> 

template<typename T> 
struct Node
{
 
    T data; 
    Node* next; 
};

template<typename T> 
class Stack 
{
private: 
    Node<int> *top = nullptr; 
public: 
    Stack(); 
    void push(T x); 
    T pop(); 
    bool isEmpty();
    void Display(); 
};

template<typename T> 
Stack<T>::Stack() {top == nullptr;}

template<typename T> 
void Stack<T>::push(T x)
{
    Node<int>* tmp = new Node<int>; 
    tmp->data = x; 
    tmp->next = top; 
    top = tmp; 
}

template<typename T> 
bool Stack<T>::isEmpty(){return top == nullptr;}

template<typename T> 
T Stack<T>::pop()
{
    T x = T(); 
    Node<int>* tmp = new Node<int>; 
    if(isEmpty()) 
        throw std::out_of_range("stack is empty cannot pop"); 
    else 
    {
        tmp = top; 
        top = top->next; 
        x = tmp->data; 
        delete tmp; 
    }
    return x; 
}

template<typename T> 
void Stack<T>::Display()
{
    Node<T>* current = top; 
    while(current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;  
    }
    std::cout << std::endl; 
}

int main(int argc, char const *argv[])
{
    Stack<int> st; 
    st.push(10); 
    st.push(20); 
    st.pop(); 

    st.Display(); 
    return 0;
}

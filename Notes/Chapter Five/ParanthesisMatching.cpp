#include <iostream> 
#include <stdexcept> 
#include <string> 

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
    Node<char> *top = nullptr; 
public: 
    Stack() {top == nullptr;}
    void push(T x) 
    {
        struct Node<char>* tmp = new Node<char>; 
        tmp->data = x; 
        tmp->next = top; 
        top = tmp; 
    } 
    T pop()
    {
         
        struct Node<char>* tmp = new Node<char>; 
        
        if(isEmpty()) {throw std::out_of_range("Stack is empty");}

        T x = tmp->data;
        tmp = top; 
        top = top->next; 
        delete tmp;
        return x;  
    } 
    bool isEmpty()
    {
        return top == nullptr; 
    }
    void Display()
    {
        struct Node<char>* current = top; 
        while(current != nullptr)
        {
            std::cout << current->data << " "; 
            current = current->next; 
        }
    } 
    bool isBalanced(const char* exp) 
    {
        int i; 
        for(i = 0; exp[i] !='\0'; ++i)
        {
            if(exp[i] == '(') push(exp[i]); 
            else if(exp[i] == ')')
            {
                if(isEmpty()) throw std::out_of_range("There are no elements in the stack"); 
                pop(); 
            }
        }
        if(top == nullptr)
            return true; 
        return false; 
    }
};
int main(int argc, char const *argv[])
{

    const char* exp = "(a + b)"; 
    Stack<char> st; 

    bool balanced = st.isBalanced(exp);
    if (balanced)
        std::cout << "The expression is balanced." << std::endl;
    else
        std::cout << "The expression is not balanced." << std::endl;
    return 0;
}

#include <iostream> 
#include <stdexcept> 

template <typename T> 
struct Node
{
    T data; 
    struct Node* next; 
};

template <typename T> 
class Stack
{
    struct Node<char>* top = nullptr; 
public: 
    Stack() {top == nullptr;}
    ~Stack() {delete top;}
    void push(T x)
    {
        struct Node<char>* tmp = new Node<char>; 
        tmp->data = x; 
        tmp->next = top; 
        top = tmp; 
    }
    T pop()
    {
        struct Node<char>* tmp = top; // dont forget tmp to first
        T x = tmp->data; 
        top = top->next; 
        delete tmp; 
        return x; 
    }
    T peek() {return top->data;}
    bool isEmpty() {return top == nullptr;}
    bool isValid(const char* exp)
    {
        int i; 
        for(i =  0; exp[i] != '\0'; ++i)
        {
            if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
                push(exp[i]); 
            else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if(isEmpty()) throw std::out_of_range("Stack is already empty expression invalid"); 
                
                char testTop = peek(); 
                if((exp[i] == ')' && testTop != '(') || (exp[i] == '}' && testTop != '{') || (exp[i] == ']' && testTop != '['))
                {
                    return false;  
                }
                pop(); 
            } 
        }
        if(isEmpty()) return true; 
        return false; 
    }
    void display() 
    {
        struct Node<char>* current = top; 
        while(current != nullptr)
        {
            std::cout << current->data << " "; 
            current = current->next; 
        }
    }
};

int main(int argc, char const *argv[])
{
    const char* exp = "{ ( a + b ) * c1 }"; 
    const char* exp2 = "{ ( a + b ) * c1 ] ";
    const char* exp3 = "( ( a + b ) * c1 ) / 15 )";
    Stack<char> st; 

    bool test = st.isValid(exp); 
    bool test1 = st.isValid(exp2);
    bool test2 = st.isValid(exp3);

    if(test) std::cout << "Exp is valid" << std::endl; 
    else std::cout << "Exp is not valid" << std::endl;

    if(test1) std::cout << "Exp is valid" << std::endl; 
    else std::cout << "Exp is not valid" << std::endl;  

    if(test2) std::cout << "Exp is valid" << std::endl; 
    else std::cout << "Exp is not valid" << std::endl; 
    return 0;
}

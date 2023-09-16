#include <iostream> 
#include <stdexcept> 

template <typename T> 
struct Stack
{
    size_t size; 
    int top; // top of the stack and index
    T* S; // Store our elements
};

void create(struct Stack<int> *st)
{
    st->top = -1; 
    st->size = 5; 
    st->S = new int[st->size]; 
}

void Display(struct Stack<int>* st)
{
    int i; 
    for(i = st->top; i >= 0; --i)
        std::cout << st->S[i] << " "; 
    std::cout << std::endl; 
}

bool isFull(struct Stack<int>* st){return st->top == st->size - 1;}
 
bool isEmpty(struct Stack<int>* st){return st->top == -1;}

template <typename T> 
void push(struct Stack<int>* st, T x)
{
    if(isFull(st))
        throw std::out_of_range("Stack Overflow Max is 5"); 
    else 
    {
        st->top++; // increasing the top 
        st->S[st->top] = x; // Storing elements 
    }
}

template <typename T> 
T pop(struct Stack<int>* st)
{
    T x = T(); // default val

    if(isEmpty(st))
        throw std::out_of_range("Stack Underflow cannot go past 0"); 
    else 
        x = st->S[st->top--];
    return x; 
}

template <typename T> 
T peek(struct Stack<int> *st, int index)
{
    if (st->top - index < 0 || index < 0 || index > st->top)
        throw std::out_of_range("Invalid index");
    return st->S[st->top - index];
}


template<typename T> 
T top(struct Stack<int>* st)
{
    if(!isEmpty(st))
        return st->S[st->top]; 
    return T(); 
} 

int main(int argc, char const *argv[])
{
    struct Stack<int> st; 
    create(&st); 
    push(&st, 10); 
    push(&st, 20); 
    push(&st, 30); 
    Display(&st); 
    std::cout << top<int>(&st) << std::endl; 
    std::cout << peek<int>(&st, 2) << std::endl;
    pop<int>(&st);
    pop<int>(&st);
    Display(&st); 
    return 0;
}

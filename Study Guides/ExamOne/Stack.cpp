#include <iostream>

// Top must always start at negative one

template <typename T>
class ArrayStack
{
    T* array;
    int top;
    int Maxsize;
    int numberOfElements;

public:
    ArrayStack(int capacity) : Maxsize(capacity), top(-1), numberOfElements(0)
    {
        array = new T[Maxsize];
    }

    ~ArrayStack()
    {
        delete[] array;
    }

    void push(const T& data)
    {
        if (top < Maxsize - 1) // Check for stack overflow
        {
            top++;
            array[top] = data;
            numberOfElements++;
        }
        else
        {
            std::cout << "Stack is full. Cannot push " << data << std::endl;
        }
    }

    void pop()
    {
        if (!isEmpty()) // Check for stack underflow
        {
            top--;
            numberOfElements--;
        }
        else
        {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    T& topS()
    {
        if (!isEmpty())
        {
            return array[top];
        }
        throw std::runtime_error("Stack is empty. Cannot get top element.");
    }

    bool isEmpty()
    {
        return numberOfElements == 0;
    }
    void print()
    {
        for(int i = 0; i < numberOfElements; ++i)
            std::cout << array[i] << " "; 
        std::cout << std::endl;
    }
};

int main(int argc, char const* argv[])
{
    ArrayStack<int> stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.print(); 
    stack.pop(); 
    stack.print(); 
   
    if(stack.isEmpty()) std::cout << "is empty";
    else std::cout << "Not empty";
    std::cout << std::endl; 
    std::cout << stack.topS(); 
    return 0;
}

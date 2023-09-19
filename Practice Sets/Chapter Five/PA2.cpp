#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

template <typename T>
struct stack
{
    size_t size;
    int top;
    T *arr;
};

template <typename T>
class MyArrayStack
{
    stack<T> *st;

public:
    MyArrayStack() { st = nullptr; }
    void create()
    {
        st = new stack<T>;
        st->top = -1;
        st->size = 100;
        st->arr = new T[st->size];
    }
    bool isFull() { return st->top == static_cast<int>(st->size) - 1; }
    bool isEmpty() { return st->top == -1; }
    void push(T x)
    {
        if (isFull())
            throw std::out_of_range("Stack Overflow");
        st->top++;
        st->arr[st->top] = x;
    }
    T pop()
    {

        if (isEmpty())
            throw std::out_of_range("Stack Underflow");
        T x = st->arr[st->top];
        st->top--;
        return x;
    }
    T peek() { return st->arr[st->top]; }
    void display()
    {
        for (int i = st->top; i >= 0; --i)
            std::cout << st->arr[i] << " ";
        std::cout << std::endl;
    }
    int isOperand(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return 0;
        return 1;
    }
};
int Eval(const char *postfix)
{

    int r, x2, x1;
    MyArrayStack<int> st;
    st.create();
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (std::isdigit(postfix[i]))
        {
            int op = 0;
            while (std::isdigit(postfix[i]))
            {
                op = op * 10 + (postfix[i] - '0');
                i++;
            }
            st.push(op);
        }
        else if (postfix[i] == ' ')
            i++;
        else
        {
            x2 = st.pop();
            x1 = st.pop();

            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                if (x2 == 0)
                    throw std::runtime_error("Divide by zero");
                r = x1 / x2;
                break;
            case '^':
                r = std::pow(x1, x2);
                break;
            }
            st.push(r);
            i++;
        }
    }
    return st.pop();
}

int main(int argc, char const *argv[])
{
    const char *postfix = "17 2 3 + / 13 -";
    const char *postfix1 = "5 2 3 ^ *";
    const char *postfix2 = "2 3 2 ^ ^";

    MyArrayStack<int> intStack;
    intStack.create();
    std::cout << Eval(postfix) << std::endl;
    std::cout << Eval(postfix1) << std::endl;
    std::cout << Eval(postfix2) << std::endl;
    return 0;
}

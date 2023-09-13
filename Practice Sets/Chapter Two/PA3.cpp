#include <iostream> 
#include <utility>

template <typename A, typename B> 
class MyPair
{
    A first; 
    B second; 
public: 
    MyPair()
    {
        first = A(); 
        second = B(); 
    }
    MyPair(A a, B b)
    {
        first = a; 
        second = b; 
    }
    A getFirst() {return first;}
    B getSecond() {return second;}
};

MyPair<int, int> LinearFibonacci(int num)
{
    if(num <= 1)
        return MyPair<int, int>(num, 0); 
    else 
    {
        MyPair<int, int> prev = LinearFibonacci(num - 1);
        return MyPair<int, int>(prev.getFirst() + prev.getSecond(), prev.getFirst()); 

    }
}

int main()
{
    int num; 
    std::cin >> num; 

    MyPair<int, int> res = LinearFibonacci(num); 
    int Fk = res.getFirst(); 
    int Fk_subtraction = res.getSecond(); 

    std::cout << Fk << " "; 
    std::cout << Fk_subtraction << " " << std::endl; 
}


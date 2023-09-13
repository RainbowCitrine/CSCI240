#include <iostream>
#include <string> 

int SIZE = 0;
std::string Names[10];

void InserFront(std::string s)
{
    if (SIZE == 10)
    {
        std::cout << "Heap overflow" << std::endl;
        return;
    }

    SIZE++;

    for (int i = SIZE - 2; i >= 0; i--)
    {
        Names[i + 1] = Names[i];
    }

    
    Names[0] = s;
}

void InsertRear(std::string s)
{
    if (SIZE == 10)
    {
        std::cout << "Heap overflow" << std::endl;
        return;
    }

    SIZE++;

    Names[SIZE - 1] = s;
}

void Remove(std::string s)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (Names[i] == s)
        {
            for (int j = i; j < SIZE; j++)
            {
                Names[j] = Names[j + 1];
            }
            SIZE--;
        }
    }

}

void print()
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << Names[i] << " ";
    }
}

void recursivePrint(int index = 0)
{
    if (index >= SIZE) 
    {
        return; 
    }

    std::cout << Names[index] << " ";

    recursivePrint(index + 1); 
}

int main()
{
    InserFront("Jo");
    InserFront("Jane");
    InserFront("John");
    InsertRear("Kim");
    Remove("Jo");
    print();
    std::cout << std::endl; 
    std::cout << "Recursive Print "; 
    recursivePrint(); 
    return 0;
}

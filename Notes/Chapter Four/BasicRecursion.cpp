#include <iostream> 

int globalVar = 0; 

void func(int num)
{
    if(num > 0)
    {
        std::cout << num << " "; // print 
        func(num - 1); // subtract one
    }
}

void ReverseFunc(int num)
{
    if(num > 0)
    {
        ReverseFunc(num - 1); 
        std::cout << num << " "; 
    }
}

int fun(int n)
{
    static int x = 0; 
    if(n > 0)
    {
        x++; 
        return fun(n - 1) + x; 
    }
    return 0; 
}

int globalFunc(int n)
{
    if(n > 0)
    {
        globalVar++; 
        return globalFunc(n - 1) + globalVar; 
    }
}

int main(int argc, char* const argv[])
{

    int R1 = globalFunc(5); 
    std::cout << R1 << std::endl; 

    int R2 = globalFunc(5); 
    std::cout << R2 << std::endl; 
}
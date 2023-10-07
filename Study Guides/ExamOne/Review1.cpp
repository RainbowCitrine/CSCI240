/*

• Write a C++ function or a Java method that accepts a positive integer n and  returns true of n is a power of 2. 


*/

#include <iostream> 

bool PowTwo(int n)
{
    if(n == 0) std::cout << "ZERO" << std::endl;
    while(n != 1)
    {
        if(n % 2 != 0)
            return false; 
        n = n / 2; 
    }
    return true; 
}

int main()
{
    PowTwo(64) ? std::cout << "Is power of two\n" : std::cout << "NO!";
}
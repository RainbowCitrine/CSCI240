#include <iostream> 
/*

Write a short C++ function that takes an integer n and returns the sum of
all the odd integers smaller than n.

*/

int oddSum(int n)
{
    int sum = 0; 
    for(int i = 1; i <= n; ++i)
        if(i % 2 != 0)
            sum = sum + i; 
    return sum; 
}

int main(int argc, char const *argv[])
{
    std::cout << oddSum(10) << std::endl; 
    return 0;
}

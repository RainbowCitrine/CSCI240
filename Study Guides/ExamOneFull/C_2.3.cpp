/*

Most modern C++ compilers have optimizers that can detect simple cases
when it is logically impossible for certain statements in a program to ever
be executed. In such cases, the compiler warns the programmer about the
useless code. Write a short C++ function that contains code for which it
is provably impossible for that code to ever be executed, but your favorite
C++ compiler does not detect this fact.


*/

#include <iostream> 
#include <stdexcept> 

void impossible()
{
    throw std::runtime_error("This program can't run"); 
}

int main(int argc, char const *argv[])
{
    std::cout << "test"; 
    impossible(); 
    return 0;
}

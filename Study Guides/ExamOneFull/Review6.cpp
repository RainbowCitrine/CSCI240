#include <iostream> 

int sum(int n)
{
    if(n == 0) return -1; 
    else return n + sum(n - 1);
}
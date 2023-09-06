#include <iostream> 

int odd(int n)
{
    int sum = 0; 
    int i; 
    for(i = 1; i <= n; ++i)
    {
        if(i % 2 == 1)
        {
            sum += i; 
        }
    }
    return sum; 
}

int main()
{
   int sum = odd(25); 
   std::cout << "Sume is: " << sum << std::endl; 
}
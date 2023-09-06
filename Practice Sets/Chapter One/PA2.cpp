#include <iostream> 
#include <cstdlib> 
#include <ctime> 

int main()
{
    std::srand(std::time(0)); 
    
    for(int i = 5; i <=100; i +=5)
    {
        int inc = 0; 
        for(int j = 0; j < 10; ++j)
        {
            int days[365] = {0}; 
            bool flag = false; 
            for(int k = 0; k < i; ++k)
            {  
                int birthdays = rand() % 365; 
                if(days[birthdays] == 1)
                {
                    flag = true; 
                    break; 
                }
                days[birthdays] = 1; 
            }
            if(flag)
            {
                inc++; 
            }
        }
        std::cout << i << " " << inc << std::endl; 
    }
}
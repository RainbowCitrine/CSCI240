#include <iostream> 

bool formula(int a, int b, int c)
{
    if(a + b == c)
        return true; 
    else if(a == b + c)
        return true; 
    else if(b == a + c)
        return true;
    
    if(a - b == c)
        return true;
    else if(a == b - c)
        return true; 
    else if(b == a - c)
        return true; 

    if(a * b == c)
        return true; 
    else if(a == b * c)
        return true; 

return false; 
}
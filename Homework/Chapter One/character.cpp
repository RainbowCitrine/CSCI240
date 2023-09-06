#include <iostream> 
#include <string>
#include <algorithm>

void permute(std::string str, int left, int right)
{
    if(left == right)
        std::cout << str << std::endl; 
    else 
    {
        for(int i = left; i <= right; ++i)
        {
            std::swap(str[left], str[i]); 
            permute(str, left +1, right); 
            std::swap(str[left], str[i]); 
        }
    }
}
int main(int argc, char const *argv[])
{
    std::string str = "abcdef"; 
    permute(str, 0, str.size() -1); 
    return 0;
}

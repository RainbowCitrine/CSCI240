#include <iostream> 

int main()
{
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}}; 
    for(int i  =0; i < 3; ++i)
    {
        for(int j = 0; j<4; ++j)
            std::cout << A[i][j] << " ";
        std::cout << std::endl; 
    } 
    return 0; 
}
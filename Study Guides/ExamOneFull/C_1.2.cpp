#include <iostream> 

/*
    Write a short C++ function that takes an array of int values and determines
    if there is a pair of numbers in the array whose product is even.
*/

bool check(int arr[], const int size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = i + 1; j < size; ++j)
        {
            if((arr[i] * arr[j]) % 2 == 0)
            {
                return true; 
            }
        }
    }
    return false; 
}

int main(int argc, char const *argv[])
{
    std::cout << "test" << std::endl; 
    int arr[] = {1, 3, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    bool result = check(arr, size);

    if(result) std::cout << "Pair"; 
    else std::cout << "No pair"; 
    std::cout << std::endl; 
    return 0;
}

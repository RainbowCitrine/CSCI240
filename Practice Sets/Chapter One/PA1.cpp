#include <iostream> 

bool check(int arr[], const int SIZE)
{
    for(int i = 0; i < SIZE-1; ++i) // Checks up to the second last element 
        for(int j = i + 1; j < SIZE; ++j) // Checks from 2 to the last element
            if(arr[i] == arr[j]) // Checks if all values are true
                return true; 
    return false; 
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,7,2,6,4};
    int arr2[] = {5,7,2,6,4,2};

    const int SIZE = sizeof(arr) / sizeof(int); 
    const int SIZE2 = sizeof(arr2) / sizeof(int); 

    if(check(arr, SIZE))
        std::cout << "Two or more values are the same."; 
    else 
        std::cout << "All values are distinct" << std::endl; 

    if(check(arr2, SIZE2))
        std::cout << "Two or more values are the same."; 
    else 
        std::cout << "All values are distinct" << std::endl; 
    
    return 0;
}

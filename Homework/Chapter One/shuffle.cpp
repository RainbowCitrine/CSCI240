#include <iostream> 
#include <ctime> 
#include <cstdlib> 
#include <algorithm> 
#include <random>


void shuff(int arr[], int size)
{
    unsigned seed = 0; 

    std::shuffle(arr, arr + size, std::default_random_engine(seed));
    
    for(int i = 0; i <size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl; 
}

int main()
{
    int arr[52] = {0};
    std::srand(std::time(0)); 

    for(int i = 1; i <= 52; ++i)
    {
        arr[i] = (std::rand() % 52)+1; 
    }
    shuff(arr, 52);
}
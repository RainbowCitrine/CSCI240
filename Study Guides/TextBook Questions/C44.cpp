#include <iostream> 
#include <algorithm> 

void largest(int arr[], int n)
{
    for(int i = 0; i < 10; ++i) // 1
    {
        int max = i; // 1
        for(int j = i + 1; j < n; ++j) // n + 1
        {
            if(arr[j] > arr[max]) // n
            {
                max = j;  // n 
            }
        }
        std::swap(arr[i], arr[max]); // 1
    }
    //O(n)
    // 3n + 4 
}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 1, 4, 20, 2, 50, 60, 80, 70, 99, 300, 2000, 1000}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    largest(arr, size); 
    for(int i = 0; i < 10 && i < size; ++i)
    {
        std::cout << arr[i] << " "; 
    }
    return 0;
}

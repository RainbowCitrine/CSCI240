/*

Describe an efficient algorithm for finding the 10 largest elements in an
array of size n. What is the running time of your algorithm?


*/

#include <iostream> 
#include <algorithm>

int findMax(int arr[], int n)
{
    for(int i  = 0; i < 10; ++i) // pick up the first index
    {
        int maxIndex = i; 
        for(int j = i + 1; j < n; ++j)
        {
            if(arr[j] > arr[maxIndex])
                maxIndex = j; 
        }
        std::swap(arr[i], arr[maxIndex]); 
    }

    // Time complexity is O(N)
}

int main(int argc, char const *argv[])
{

    return 0;
}

// Algorithm is O(n)
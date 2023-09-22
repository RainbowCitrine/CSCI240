#include <iostream> 

int max(int arr[], int n)
{
    if(n == 1)
        return arr[0]; 
    int pos = max(arr, n - 1);
    if(pos > arr[n - 1]) return pos;
    else return arr[n - 1]; 
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(int); 
    std::cout << max(arr, size) << " "; 
    return 0;
}

#include <iostream> 
#define N 10
int size = 5; 
void insertPosition(int arr[], int index, int data)
{
    for(int i = size - 1; i >= index; --i)
    {
        arr[i + 1] = arr[i]; 
    }
    arr[index] = data; 
    size++; 
}

int main()
{
    int arr[N] = {1, 2, 3, 4, 5};
    int insertIndex = 2;
    int valueToInsert = 10;

    insertPosition(arr, insertIndex, valueToInsert);

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}






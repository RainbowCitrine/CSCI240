#include <iostream> 
#include <string> 
#define N 10


void insertBeginning(std::string arr[], int &SIZE, std::string element)
{
    //Check if the size is bigger than the size 
    if(SIZE + 1 < N)
    {
        for(int i = SIZE; i > 0; --i)
        {
            arr[i] = arr[i - 1]; // shifting to the left 
        }
        arr[0] = element; // inserting the element
        ++SIZE; 
    }
}
void insertBack(std::string arr[], int &SIZE, std::string element)
{
    if(SIZE + 1 < N)
    {
        arr[SIZE] = element; 
        ++SIZE; 
    }
}
void remove(std::string arr[], int &SIZE, std::string element)
{
    int i; 
    for(i = 0; i < SIZE; ++i)
        if(arr[i] == element)
            break; 
    
    if(i < SIZE)
    {
        SIZE = SIZE - 1;
        for(int j = i; j < SIZE; ++j)
            arr[j] = arr[j + 1]; 
    }
}


void display(std::string arr[], int SIZE)
{
    for(int i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " "; 
}

int main()
{
    std::string arr[N] = {"Jo"}; 
    int SIZE = 1;
    insertBeginning(arr, SIZE, "Test"); 
    insertBack(arr, SIZE, "Test"); 
    remove(arr, SIZE, "Test"); 
    display(arr, SIZE); 

}
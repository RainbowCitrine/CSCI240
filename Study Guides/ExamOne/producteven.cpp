/*

Write a short C++ function that takes an array of int values and determines
if there is a pair of numbers in the array whose product is even.

*/

bool productEven(int arr[], int numElements)
{
    for(int i = 0; i < numElements; ++i)
    {
        for(int j = i + 1; j < numElements; ++j)
        {
            if((arr[i] * arr[j] % 2) == 0)
                return true; 
        }
    }
    return false; 
}
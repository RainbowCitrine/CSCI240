#include <iostream> 
#include <string> 

template <typename T> 
class ArrayList 
{
    T* data; 
    int capacity; //capacity of array 
    int size; //number of elements list contains
    
public: 
    ArrayList()
    {
        data = new T[5]; 
        capacity = 5; 
        size = 0; 
    }
    bool needtoreize() {return capacity == size;} // Returns if data is equal to the size
    void resize()
    {
        //resize the arry so it can have more data 
        //precondition - size of the array == size of the data
        //post condition - new array that's twice the size 

        //get a new temp array 

        T* temp = new T[capacity * 2]; 
        for(int i = 0; i < capacity; ++i)
            temp[i] = data[i]; //grabs data to the temp
        data = temp; // sets it equal 
        capacity *= 2;
    }
    bool contains(T item)
    {
        return (indexof(item) > -1); 
    }
    int indexof(T item)
    {
        for(int i = 0; i <= size; ++i)
            if(item == data[i])
                return i; 
        return -1; 
    }
    T get(int index)
    {
        if(index <= size || index >= size) return data[index]; 
    }
    int sizearr() {return size;}
    void add(T item)
    {
        // add the item to the end of the list 
        //checks to see if there's enough space 

        if(needtoreize())
            resize(); 
        
        data[size] = item; 
        size++; 
    }
    void add(int index, T item)
    {
        //adds item to the indicated size

        if(needtoreize())
            resize(); 
        for(int i = size; i > index; --i)
        {
            data[i] = data[i - 1]; 
        }
        data[index] = item; 
        size++; 
    }
    void set(int index, T item)
    {
        if(index >= 0 && index <= size)
            data[index] = item; 
    }
    void remove(int index)
    {
        for(int i = index; i < size - 1; ++i)
            data[i] = data[i + 1]; // data copied 
        size--; 
    }
    void removeVal(T item)
    {
        int index = indexof(item); 
        if(index != -1)
        {
            for(int i = index; i < size - 1; ++i)
                data[i] = data[i + 1]; 
            size--; 
        }
    }
    void display()
    {
        std::cout << "List of elements: "; 
        for(int i = 0; i < size; ++i)
        {
            std::cout << data[i] << " "; 
        }
        std::cout << std::endl; 
    }
};

int main(int argc, char const *argv[])
{
    ArrayList<std::string> mylist; 
    mylist.add(0, "Two"); 
    mylist.add(1, "Three"); 
    mylist.add(0, "One"); 
    mylist.add(3, "Four"); 
    mylist.display(); 
    mylist.remove(0); 
    mylist.remove(2); 
    mylist.add(1, "Noah Rainbow"); 
    mylist.display(); 
    std::cout << std::endl; 
    return 0;
}

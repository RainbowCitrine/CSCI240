/*
 Describe what changes need to be made to the extendable array implementation given in Code Fragment 6.2 in order to shrink the size N of the array
by half any time the number of elements in the vector goes below N/4.

*/


bool needToResize() { return size < capacity / 4; } // Check if we need to shrink

    void shrink() {
        // Resize the array to half of its current capacity
        int newCapacity = capacity / 2;
        T* temp = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity = newCapacity;
    }

#include <iostream> 
#include "PriorityHeap.h"

int main(int argc, char const *argv[])
{
    HeapPriorityQueue<int, MaxComp<int>> maxPQ; 
    HeapPriorityQueue<int, MinComp<int>> minPQ; 

    minPQ.insert(5);
    minPQ.insert(4);
    minPQ.insert(7);
    minPQ.insert(1);
    std::cout << minPQ.min() << std::endl;
    minPQ.removeMin();
    minPQ.insert(3);
    minPQ.insert(6);
    std::cout << minPQ.min() << std::endl;
    minPQ.removeMin();
    std::cout << minPQ.min() << std::endl;
    minPQ.removeMin();
    minPQ.insert(8);
    std::cout << minPQ.min() << std::endl;
    minPQ.removeMin();
    minPQ.insert(2);
    std::cout << minPQ.min() << std::endl;
    minPQ.removeMin();
    std::cout << minPQ.min() << std::endl;
    minPQ.removeMin();

    std::cout << std::endl;

    maxPQ.insert(5);
    maxPQ.insert(4);
    maxPQ.insert(7);
    maxPQ.insert(1);
    std::cout << maxPQ.min() << std::endl;
    maxPQ.removeMin();
    maxPQ.insert(3);
    maxPQ.insert(6);
    std::cout << maxPQ.min() << std::endl;
    maxPQ.removeMin();
    std::cout << maxPQ.min() << std::endl;
    maxPQ.removeMin();
    maxPQ.insert(8);
    std::cout << maxPQ.min() << std::endl;
    maxPQ.removeMin();
    maxPQ.insert(2);
    std::cout << maxPQ.min() << std::endl;
    maxPQ.removeMin();
    std::cout << maxPQ.min() << std::endl;
    maxPQ.removeMin();

    return 0;
}

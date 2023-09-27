#include <iostream>
#include <string>
#include "NodeList.h" 

int main() {
    NodeList stringList; 

    stringList.insertFront("Two");

    stringList.insertBack("Three");

    stringList.insertFront("One");

    stringList.insertBack("Four");

    NodeList::Iterator it = stringList.begin();
    while (it != stringList.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    stringList.eraseFront();

    stringList.eraseBack();

    NodeList::Iterator advancedIt = stringList.begin();
    ++advancedIt;

    stringList.insert(advancedIt, "Noah Rainbow");

    it = stringList.begin();
    while (it != stringList.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    return 0;
}

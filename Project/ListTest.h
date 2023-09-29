#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include "SinglyLinkedList..h" // Include your SinglyLinkedList header file

void testSinglyLinkedList() {
    SinglyLinkedList<std::string> list;
    
    // Test create and display
    list.create("Class One");
    list.Display(); // Expected output: Class One

    // Test insertFront and display
    list.insertFront("Class None");
    list.Display(); // Expected output: Class None Class One

    // Test insertBack and display
    list.insertBack("Class Two");
    list.Display(); // Expected output: Class None Class One Class Two

    // Test insertMiddle and display
    list.insertMiddle(2, "Class Five");
    list.Display(); // Expected output: Class None Class One Class Five Class Two

    // Test Remove and display
    list.Remove("Class None");
    list.Display(); // Expected output: Class One Class Five Class Two

    list.Remove("Class Five");
    list.Display(); // Expected output: Class One Class Five Class Two
}

#endif 

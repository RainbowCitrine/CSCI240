#include <iostream>
#include <string>

template <typename T>
struct Node {
    T data;              // data
    struct Node* next;   // linker
};

void insertFront(struct Node<std::string>*& first, std::string element) {
    struct Node<std::string>* temp = new Node<std::string>;
    temp->data = element;   // assigning element
    temp->next = first;     // linker to the first node
    first = temp;
}

void insertRear(struct Node<std::string>*& first, std::string element) {
    Node<std::string>* temp = new Node<std::string>;
    temp->data = element;
    temp->next = nullptr;
    if (first == nullptr) {
        first = temp;
    } else {
        Node<std::string>* current = first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }
}

std::string Remove(struct Node<std::string>*& first, std::string element) {
    Node<std::string>* previous = nullptr;
    Node<std::string>* current = first;

    while (current != nullptr) {
        if (current->data == element) {
            break;
        } else // to advance if not found
        {
            previous = current;
            current = current->next;
        }
    }
    if (current != nullptr) {
        previous->next = current->next;
        element = current->data;
        delete current;
    } else if (previous == nullptr) {
        current = first;
        first = first->next;
        element = previous->data;
        delete current;
    }
    return element;
}

void display(struct Node<std::string>*& first) {
    struct Node<std::string>* current = first;

    while (current != nullptr) {
        std::cout << current->data << " "; // second Node data
        current = current->next;           // second node address
    }
}

void recPrintAll(struct Node<std::string>*& first) {
    if (first != nullptr) {
        std::cout << first->data << " ";
        recPrintAll(first->next);
    }
}

int main(int argc, char const* argv[]) {
    Node<std::string>* head = nullptr;

    insertFront(head, "Jo");
    insertFront(head, "Jane");
    insertRear(head, "John");
    insertRear(head, "Kim");
    Remove(head, "Jo");
    Remove(head, "Kim");
    display(head);

    std::cout << "\nRecursive Print: ";
    recPrintAll(head);

    return 0;
}

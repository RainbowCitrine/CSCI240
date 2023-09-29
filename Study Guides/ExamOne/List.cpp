#include <iostream>

template <typename T>
struct Node
{
    Node *prev;
    T data;
    Node *next;
};

template <typename T>
class NodeList
{
public:
    class Iterator
    {
    public:
        T &operator*()
        {
            return head->data;
        }
        bool operator==(const Iterator &tmp)
        {
            return head == tmp.head;
        }
        bool operator!=(const Iterator &tmp)
        {
            return head != tmp.head;
        }
        Iterator &operator++()
        {
            head = head->next;
            return *this;
        }
        Iterator &operator--()
        {
            head = head->prev;
            return *this;
        }

        friend class NodeList<T>;

    private:
        Node<T> *head;
        Iterator(Node<T> *u)
        {
            head = u;
        }
    };

public:
    NodeList()
    {
        sizeList = 0;
        header = new Node<T>;
        trailer = new Node<T>;
        header->next = trailer;
        trailer->prev = header;
    }
    void insert(const Iterator &first, const T &data)
    {
        Node<T> *tmp = first.head;
        Node<T> *predecessor = tmp->prev;
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        newNode->next = tmp;
        tmp->prev = newNode;
        newNode->prev = predecessor;
        predecessor->next = newNode;
        sizeList++;
    }
    void erase(const Iterator &first)
    {
        Node<T> *removenode = first.head;
        Node<T> *successor = removenode->next;
        Node<T> *predecessor = removenode->prev;
        successor->prev = predecessor;
        predecessor->next = successor;
        delete removenode;
        sizeList--;
    }
    void insertFront(const T &data)
    {
        insert(begin(), data);
    }
    void insertBack(const T &data)
    {
        insert(end(), data);
    }
    void eraseFront()
    {
        erase(begin());
    }
    void eraseBack()
    {
        erase(--end());
    }
    size_t size()
    {
        return sizeList;
    }
    bool empty()
    {
        return sizeList == 0;
    }
    Iterator begin()
    {
        return Iterator(header->next);
    }
    Iterator end()
    {
        return Iterator(trailer);
    }

private:
    struct Node<T> *header;
    struct Node<T> *trailer;
    size_t sizeList;
};
void test()
{
    NodeList<int> intList;

    std::cout << "Is the list empty? " << (intList.empty() ? "Yes" : "No") << std::endl;

    intList.insertFront(10);
    intList.insertFront(20);
    intList.insertFront(30);

    intList.insertBack(5);
    intList.insertBack(1);

    std::cout << "List size: " << intList.size() << std::endl;

    NodeList<int>::Iterator it = intList.begin();
    std::cout << "List elements: ";
    while (it != intList.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    intList.eraseFront();
    intList.eraseBack();

    std::cout << "List size after erasing front and back: " << intList.size() << std::endl;

    it = intList.begin();
    std::cout << "Modified list elements: ";
    while (it != intList.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}
int main(int argc, char const *argv[])
{
    test(); 
    return 0;
}

#include <iostream>
using namespace std;

template <typename T>
class LDLL;

template <typename T>
class DNode
{
    T info;
    DNode<T>* next;
    DNode<T>* previous;

public:
    DNode()
    {
        next = nullptr;
        previous = nullptr;
    }

    DNode(T value)
    {
        info = value;
        next = nullptr;
        previous = nullptr;
    }

    friend class LDLL<T>;
};

template <typename T>
class LDLL
{
    DNode<T>* head;

public:
    LDLL()
    {
        head = nullptr;
    }

    ~LDLL()
    {
        DNode<T>* temp = head;
        while (temp != nullptr)
        {
            DNode<T>* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    void insertAtHead(T val)
    {
        DNode<T>* nodeptr = new DNode<T>(val);
        if (head == nullptr)
        {
            head = nodeptr;
            return;
        }
        head->previous = nodeptr;
        nodeptr->next = head;
        head = nodeptr;
    }

    void insertAtTail(T val)
    {
        DNode<T>* nodeptr = new DNode<T>(val);
        if (head == nullptr)
        {
            head = nodeptr;
            return;
        }
        DNode<T>* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nodeptr;
        nodeptr->previous = temp;
    }

    void display()
    {
        if (head == nullptr)
        {
            return;
        }
        DNode<T>* nodeptr = head;
        while (nodeptr != nullptr)
        {
            cout << nodeptr->info << "\n";
            nodeptr = nodeptr->next;
        }
    }

    void insertAfter(T key, T val)
    {
        DNode<T>* nodeptr = new DNode<T>(val);
        if (head == nullptr)
        {
            return;
        }
        DNode<T>* temp = head;
        while (temp != nullptr && temp->info != key)
        {
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            if (temp->next != nullptr)
            {
                temp->next->previous = nodeptr;
                nodeptr->next = temp->next;
            }
            temp->next = nodeptr;
            nodeptr->previous = temp;
        }
    }

    void insertBefore(T key, T val)
    {
        DNode<T>* nodeptr = new DNode<T>(val);
        if (head == nullptr)
        {
            return;
        }
        DNode<T>* temp = head;
        while (temp != nullptr && temp->info != key)
        {
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            if (temp->previous != nullptr)
            {
                temp->previous->next = nodeptr;
                nodeptr->previous = temp->previous;
            }
            else // If the node before key is head
            {
                head = nodeptr;
            }
            temp->previous = nodeptr;
            nodeptr->next = temp;
        }
    }

    void remove(T key)
    {
        if (head == nullptr)
        {
            return;
        }
        DNode<T>* temp = head;
        while (temp != nullptr && temp->info != key)
        {
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            if (temp->previous != nullptr)
            {
                temp->previous->next = temp->next;
            }
            if (temp->next != nullptr)
            {
                temp->next->previous = temp->previous;
            }
            if (temp == head)
            {
                head = head->next;
            }
            delete temp;
        }
    }

    void removeAtHead()
    {
        if (head == nullptr)
        {
            return;
        }
        DNode<T>* temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->previous = nullptr;
        }
        delete temp;
    }

    void removeAtTail()
    {
        if (head == nullptr)
        {
            return;
        }
        DNode<T>* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        if (temp->previous != nullptr)
        {
            temp->previous->next = nullptr;
        }
        else // If only one node in the list
        {
            head = nullptr;
        }
        delete temp;
    }

    void removeAfter(T key)
    {
        if (head == nullptr)
        {
            return;
        }
        DNode<T>* temp = head;
        while (temp != nullptr && temp->info != key)
        {
            temp = temp->next;
        }
        if (temp != nullptr && temp->next != nullptr)
        {
            DNode<T>* p = temp->next;
            temp->next = p->next;
            if (p->next != nullptr)
            {
                p->next->previous = temp;
            }
            delete p;
        }
    }

    void removeBefore(T key)
    {
        if (head == nullptr)
        {
            return;
        }
        DNode<T>* temp = head;
        while (temp != nullptr && temp->info != key)
        {
            temp = temp->next;
        }
        if (temp != nullptr && temp->previous != nullptr)
        {
            DNode<T>* p = temp->previous;
            if (p->previous != nullptr)
            {
                p->previous->next = temp;
            }
            else // If the node before key is head
            {
                head = temp;
            }
            temp->previous = p->previous;
            delete p;
        }
    }
};

int main()
{
    LDLL<int> dll;
    dll.insertAtHead(5);
    dll.insertAtHead(3);
    dll.insertAtHead(1);
    dll.insertAtTail(7);
    dll.insertAtTail(9);
    cout << "Doubly Linked List:" << endl;
    dll.display();
    cout << endl;

    // Inserting element after a specific value
    dll.insertAfter(3, 4);
    cout << "Doubly Linked List after insertion:" << endl;
    dll.display();
    cout << endl;

    // Removing element
    dll.remove(7);
    cout << "Doubly Linked List after removal:" << endl;
    dll.display();
    cout << endl;

    // Removing the head
    dll.removeAtHead();
    cout << "Doubly Linked List after removing the head:" << endl;
    dll.display();
    cout << endl;

    // Removing the tail
    dll.removeAtTail();
    cout << "Doubly Linked List after removing the tail:" << endl;
    dll.display();
    cout << endl;

    // Inserting element before a specified value
    dll.insertBefore(4, 2);
    cout << "Doubly Linked List after insertion:" << endl;
    dll.display();
    cout << endl;

    // Removing element after a specified value
    dll.removeAfter(3);
    cout << "Doubly Linked List after removal:" << endl;
    dll.display();
    cout << endl;

    // Removing element before a specified value
    dll.removeBefore(4);
    cout << "Doubly Linked List after removal:" << endl;
    dll.display();
    cout << endl;

    return 0;
}

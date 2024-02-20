# Linear Doubly Linked List Implementation in C++

This repository contains a C++ implementation of a linear doubly linked list. It provides a flexible and efficient way to manage collections of data with bidirectional traversal capability.

## Classes Overview

### `DNode` Class

- Represents a node in the doubly linked list.
- Features:
  - Data of generic type `T`.
  - Pointers to the next (`next`) and previous (`previous`) nodes.
- Constructors:
  - Initialization with or without data.

### `LDLL` Class

- Represents the doubly linked list.
- Includes:
  - Pointer to the head node (`head`).
- Methods for:
  - Insertion (`insertAtHead`, `insertAtTail`, `insertAfter`, `insertBefore`).
  - Removal (`remove`, `removeAtHead`, `removeAtTail`, `removeAfter`, `removeBefore`).
  - Displaying the list (`display`).

## Example Usage

```cpp
int main()
{
    // Create a doubly linked list
    LDLL<int> dll;
    dll.insertAtHead(5);
    dll.insertAtHead(3);
    dll.insertAtHead(1);
    dll.insertAtTail(7);
    dll.insertAtTail(9);

    // Display the list
    cout << "Doubly Linked List:" << endl;
    dll.display();
    cout << endl;

    // Insert an element after a specific value
    dll.insertAfter(3, 4);
    cout << "After insertion:" << endl;
    dll.display();
    cout << endl;

    // Remove an element
    dll.remove(7);
    cout << "After removal:" << endl;
    dll.display();
    cout << endl;

    // Remove the head
    dll.removeAtHead();
    cout << "After removing the head:" << endl;
    dll.display();
    cout << endl;

    // Remove the tail
    dll.removeAtTail();
    cout << "After removing the tail:" << endl;
    dll.display();
    cout << endl;

    // Insert an element before a specified value
    dll.insertBefore(4, 2);
    cout << "After insertion:" << endl;
    dll.display();
    cout << endl;

    // Remove an element after a specified value
    dll.removeAfter(3);
    cout << "After removal:" << endl;
    dll.display();
    cout << endl;

    // Remove an element before a specified value
    dll.removeBefore(4);
    cout << "After removal:" << endl;
    dll.display();
    cout << endl;

    return 0;
}

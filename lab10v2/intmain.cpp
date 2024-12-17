#include <iostream>
#include <stdexcept>
#include "List.hpp"
#include "shapes.hpp"
using namespace std;

// Standalone function to sort the linked list using bubble sort
template <typename T>
void sortLinkedList(LinkedList<T>& list) {
    if (list.length() == 0 || list.length() == 1) return; // Empty or single-node list

    bool swapped;
    Node<T>* current;
    Node<T>* lastSorted = nullptr;

    do {
        swapped = false;
        current = list.getHead();

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                // Swap the data of adjacent nodes
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        lastSorted = current; // Mark the last sorted node
    } while (swapped);
}

// Example usage
int main() {
    LinkedList<int> list;

    list.add(30);
    list.add(10);
    list.add(50);
    list.add(20);
    list.add(40);
    list.add(5);

    cout << "Original list: \n";
    list.print();

    sortLinkedList(list);

    cout << "Sorted list: \n";
    list.print();

    cout << "Element at index 2: " << list.get(2) << endl;

    list.deleteNode(2);
    list.deleteNode(4);
    cout << "After deleting element at index 2, 5: \n";
    list.print();

    cout << "Info of node at index 3: " << list.get(3) << endl;

    cout << "Length: " << list.length() << endl;

    return 0;
};

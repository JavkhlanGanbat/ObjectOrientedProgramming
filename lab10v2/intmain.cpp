#include "List.hpp"
using namespace std;

// Jagsaalt dotor baigaa elementuudiig utgaar ni erembeleh functs (zuvhun int turul deer ajillana)
void sortLinkedList(LinkedList<int>& list) {
    if (list.length() == 0 || list.length() == 1) return; // hooson, esvel gantshan elementtei jagsaalt

    bool swapped;
    Node<int>* current;
    Node<int>* lastSorted = nullptr;

    do {
        swapped = false;
        current = list.getHead();

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                // 2 zangilaanii datag uur hoorond ni solih
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        lastSorted = current; // erembelegdsen suuliin zangilaag temdegleh
    } while (swapped);
}

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

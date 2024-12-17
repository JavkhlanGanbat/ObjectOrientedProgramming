#include "List.hpp"
using namespace std;

// Jagsaalt dotor baigaa elementuudiig utgaar ni erembeleh functs (zuvhun int turul deer ajillana)
void sortLinkedList(LinkedList<int>& list){
    if (list.length() == 0 || list.length() == 1) return; // hooson, esvel gantshan elementtei jagsaalt

    bool swapped;
    Node<int>* current;
    Node<int>* lastSorted = nullptr;

    do {
        swapped = false;
        current = list.getHead();

        while (current->next != lastSorted){
            if (current->data > current->next->data){
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

using namespace std;

void printMenu(){
    cout << "\n" << "1. Add element\n";
    cout << "2. Print list\n";
    cout << "3. Insert to list\n";
    cout << "4. Sort list\n";
    cout << "5. Get element at index\n";
    cout << "6. Delete element at index\n";
    cout << "7. Get length of list\n";
    cout << "0. Exit\n";
}

int main(){
    LinkedList<int> list;
    int choice, value, index;

    for (int i = 0; i < 10; ++i){
        list.add(rand() % 100 + 1);
    }

    while (true){
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1: // Add element
                cout << "Enter element to add: ";
                cin >> value;
                list.add(value);
                cout << "Element added.\n";
                break;

            case 2: // Print list
                cout << "List: \n";
                list.print();
                break;
            case 3: // Insert to list
                cout << "Enter index: ";
                cin >> index;
                list.insert(index);
                break;

            case 4: // Sort list
                sortLinkedList(list);
                cout << "List sorted.\n";
                break;

            case 5: // Get element at index
                cout << "Enter index: ";
                cin >> index;
                cout << "Element at index " << index << ": " << list.get(index) << endl;
                break;

            case 6: // Delete element at index
                cout << "Enter index to delete: ";
                cin >> index;
                list.deleteNode(index);
                cout << "Element deleted.\n";
                break;

            case 7: // Get length of list
                cout << "Length of list: " << list.length() << endl;
                break;

            case 0: // Exit
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

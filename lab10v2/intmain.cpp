#include "List.hpp"
using namespace std;

// Jagsaalt dotor baigaa elementuudiig utgaar ni erembeleh functs (zuvhun int turul deer ajillana)
void sortList(List<int>& list){
    if (list.length() == 0 || list.length() == 1) return; // hooson, esvel gantshan elementtei jagsaalt

    bool swapped;
    Node<int>* c;
    Node<int>* lastSorted = nullptr;

    do {
        swapped = false;
        c = list.getHead();

        while (c->next != lastSorted){
            if (c->data > c->next->data){
                // 2 zangilaanii datag uur hoorond ni solih
                int temp = c->data;
                c->data = c->next->data;
                c->next->data = temp;
                swapped = true;
            }
            c = c->next;
        }
        lastSorted = c; // erembelegdsen suuliin zangilaag temdegleh
    } while (swapped);
}

using namespace std;

void printMenu(){
    cout << "\n" << "1. Push_back\n";
    cout << "2. Jagsaaltiig hevleh\n";
    cout << "3. i index deer shine elem oruulah\n";
    cout << "4. Erembeleh\n";
    cout << "5. i index deerh elem haruulah\n";
    cout << "6. i index deerh elem-g ustgah\n";
    cout << "7. Jagsaaltiin urtiig avah\n";
    cout << "0. Garah\n";
}

int main(){
    List<int> list;
    int choice, value, index;

    for (int i = 0; i < 10; ++i){
        list.add(rand() % 100 + 1);
    }

    while (true){
        printMenu();
        cout << "Songoltoo oruulna uu: ";
        cin >> choice;

        switch (choice){
            case 1: // Add element
                cout << "Oruulah utgaa songono uu: ";
                cin >> value;
                list.add(value);
                cout << "Jagsaaltiin tugsguld oruullaa.\n";
                break;

            case 2: // Print list
                cout << "Jagsaalt: \n";
                list.print();
                break;
            case 3: // Insert to list
                cout << "Index: ";
                cin >> index;
                list.insert(index);
                break;

            case 4: // Sort list
                sortList(list);
                cout << "Erembelegdlee.\n";
                break;

            case 5: // Get element at index
                cout << "Index: ";
                cin >> index;
                cout << index << "-d baigaa element" << ": " << list.get(index) << endl;
                break;

            case 6: // Delete element at index
                cout << "Ali index?: ";
                cin >> index;
                list.deleteNode(index);
                cout << "Ustgasan.\n";
                break;

            case 7: // Get length of list
                cout << "Jagsaaltiin urt: " << list.length() << endl;
                break;

            case 0: // Exit
                cout << "Bye\n";
                return 0;

            default:
                cout << "No.\n";
        }
    }
}

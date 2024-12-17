#include "shapes.hpp"
#include "List.hpp"
#include <iomanip>
#include <cstdlib>
#include <ctime> 
using namespace std;


// Display function (for reference, already provided)
template <typename T>
void display(LinkedList<T>& list) {
    if (list.length() == 0) {  // Range check
        cout << "The list is empty.\n";
        return;
    }

    cout << "\n"
         << left << setw(10) << "Index"
         << left << setw(15) << "Shape"
         << left << setw(15) << "Area"
         << "Perimeter" << "\n\n";

    Node<T>* tmp = list.getHead();
    int index = 0;
    while (tmp) {
        cout << left << index << setw(9) << " ->"
             << left << setw(15) << tmp->data->getName()
             << left << setw(15) << fixed << setprecision(2) << tmp->data->getArea()
             << tmp->data->getPerimeter() << "\n";

        tmp = tmp->next;
        index++;
    }
}

// Sorting function (for reference, already provided)
template <typename T>
void sortByArea(LinkedList<T>& list) {
    if (!list.getHead() || !list.getHead()->next) return;

    bool swapped;
    Node<T>* c;
    Node<T>* last = nullptr;

    do {
        swapped = false;
        c = list.getHead();

        while (c->next != last) {
            if (c->data->getArea() > c->next->data->getArea()) {
                T temp = c->data;
                c->data = c->next->data;
                c->next->data = temp;
                swapped = true;
            }
            c = c->next;
        }
        last = c;
    } while (swapped);
}

int main() {
    srand(time(0)); // rand num generator

    LinkedList<TwoDShape*> shapes;

    // 30 random shapes
    for (int i = 0; i < 30; ++i) {
        int shapeType = rand() % 3;
        double randomSize = (rand() % 10 + 1) + (rand() % 100) / 100.0;

        if (shapeType == 0) {
            shapes.add(new Circle(randomSize));
        } else if (shapeType == 1) {
            shapes.add(new Square(randomSize));
        } else {
            shapes.add(new Triangle(randomSize));
        }
    }

    cout << "Original list:\n";
    display(shapes);

    sortByArea(shapes);

    cout << "\nSorted list (area):\n";
    display(shapes);

    cout << "Info of node at index 3: " << shapes.get(3) << endl;

    return 0;
}



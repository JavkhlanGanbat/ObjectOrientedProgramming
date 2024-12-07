#include "shapes.hpp"
#include "List.hpp"
#include <iostream>

void menu() {
    cout << "\n" << "1. Display all shapes" << endl;
    cout << "2. Add a shape" << endl;
    cout << "3. Insert a shape at an index" << endl;
    cout << "4. Get details of a shape at an index" << endl;
    cout << "5. Remove a shape at an index" << endl;
    cout << "6. Get the total number of shapes" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    LinkedList<TwoDShape> shapes;

    for (int i = 1; i <= 3; i++) {
        shapes.add(new Circle(i));
        shapes.add(new Square(i));
        shapes.add(new Triangle(i));
    }

    while (true) {
        menu();
        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting program." << endl;
            break;
        }

        switch (choice) {
        case 1:
            cout << "\nShapes in the list:" << endl;
            shapes.display();
            break;

        case 2: {
            cout << "\nAdd a shape:" << endl;
            cout << "Enter shape type (1: Circle, 2: Square, 3: Triangle): ";
            int type;
            cin >> type;
            cout << "Enter size parameter (e.g., radius or side length): ";
            double size;
            cin >> size;

            if (type == 1)
                shapes.add(new Circle(size));
            else if (type == 2)
                shapes.add(new Square(size));
            else if (type == 3)
                shapes.add(new Triangle(size));
            else
                cout << "Stop!" << endl;
            break;
        }

        case 3: {
            cout << "\nInsert a shape:" << endl;
            cout << "Shape type? (1: Circle, 2: Square, 3: Triangle): ";
            int type;
            cin >> type;
            cout << "Side len/ radius: ";
            double size;
            cin >> size;
            cout << "Index to insert at: ";
            int index;
            cin >> index;

            if (type == 1)
                shapes.insert(new Circle(size), index);
            else if (type == 2)
                shapes.insert(new Square(size), index);
            else if (type == 3)
                shapes.insert(new Triangle(size), index);
            else
                cout << "No shape of that type" << endl;
            break;
        }

        case 4: {
            cout << "\nGet a shape:" << endl;
            cout << "Enter index: ";
            int index;
            cin >> index;

            TwoDShape* shape = shapes.get(index);
            if (shape) {
                cout << "Shape: " << shape->getName()
                     << ", Side length: " << shape->getSideLength()
                     << ", Area: " << shape->getArea()
                     << ", Perimeter: " << shape->getPerimeter() << endl;
            }
            break;
        }

        case 5: {
            cout << "\nremove():" << endl;
            cout << "Enter index: ";
            int index;
            cin >> index;

            shapes.remove(index);
            break;
        }

        case 6:
            cout << "\nlength(): " << shapes.length() << endl;
            break;

        default:
            cout << "No." << endl;
            break;
        }
    }

    return 0;
}

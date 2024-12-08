#include "shapes.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

void menu() {
    cout << "\n" << "1. Print objects" << endl; // buh shapeiig haruulna
    cout << "2. Push object to the back (end of list)" << endl; // jagsaalt deer push_back uildliig hiine
    cout << "3. Insert object" << endl; // todorhoi index deer objectiig oruulna
    cout << "4. Get info of object" << endl; // index deer objectiin medeelliig haruulna
    cout << "5. Remove object" << endl; // todorhoi index deerh objectiig ustgana
    cout << "6. Get list length" << endl; // listiin urtiig haruulna
    cout << "7. Sort list by area" << endl; // listiig talbaiar holbogdono
    cout << "0. Exit" << endl; 
    cout << "Choice?: ";
}

int main() {
    List<TwoDShape> shapes;

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
            cout << "Bye" << endl;
            break;
        }

        switch (choice) {
        case 1:
            shapes.display();
            break;

        case 2: {
            cout << "Shape type? (1: Circle, 2: Square, 3: Triangle): ";
            int type;
            cin >> type;
            cout << "Size? (radius/side length): ";
            double size;
            cin >> size;

            if (type == 1) shapes.add(new Circle(size));
            else if (type == 2) shapes.add(new Square(size));
            else if (type == 3) shapes.add(new Triangle(size));
            else cout << "Stop!" << endl;
            break;
        }

        case 3: {
            cout << "Shape type? (1: Circle, 2: Square, 3: Triangle): ";
            int type;
            cin >> type;
            cout << "Side len/ radius: ";
            double size;
            cin >> size;
            cout << "Index to insert at: ";
            int index;
            cin >> index;

            if (type == 1) shapes.insert(new Circle(size), index);
            else if (type == 2) shapes.insert(new Square(size), index);
            else if (type == 3) shapes.insert(new Triangle(size), index);
            else cout << "No such type" << endl;
            break;
        }

        case 4: {
            cout << "Index?: ";
            int index;
            cin >> index;

            TwoDShape* shape = shapes.getInfo(index);
            if (shape) {
                cout << "Shape: " << shape->getName()
                     << ", L/R: " << shape->getSideLength()
                     << ", A: " << shape->getArea()
                     << ", P: " << shape->getPerimeter() << endl;
            }
            break;
        }

        case 5: {
            cout << "Index?: ";
            int index;
            cin >> index;

            shapes.remove(index);
            break;
        }

        case 6:
            cout << shapes.length() << endl;
            break;
        
        case 7:
            shapes.sortByArea();
            cout << "Done." << endl;
            break;

        default:
            cout << "No." << endl;
            break;
        }
    }

    return 0;
}

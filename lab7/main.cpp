#include "shapes.hpp"

using namespace std;

vector<TwoDShape*> shapes;

void displayShapes() {
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << i + 1 << ". " << shapes[i]->getName() << endl
             << "Position: (" << shapes[i]->getX() << ", " << shapes[i]->getY() << ")" << endl
             << "Area: " << shapes[i]->getArea() << endl
             << "Perimeter: " << shapes[i]->getPerimeter() << endl << endl;
    }
}

void createCircle() {
    double x, y, radius;
    cout << "Enter X, Y, radius of the circle: ";
    cin >> x >> y >> radius;
    shapes.push_back(new Circle(x, y, radius));
}

void createSquare() {
    double x, y, sideLength;
    cout << "Enter X, Y, side length of the square: ";
    cin >> x >> y >> sideLength;
    shapes.push_back(new Square(x, y, sideLength));
}

void createTriangle() {
    double x, y, sideLength;
    cout << "Enter X, Y, side length of the triangle: ";
    cin >> x >> y >> sideLength;
    shapes.push_back(new Triangle(x, y, sideLength));
}

void sortShapesByArea() {
    for (size_t i = 0; i < shapes.size() - 1; ++i) {
        for (size_t j = 0; j < shapes.size() - i - 1; ++j) {
            if (shapes[j]->getArea() > shapes[j + 1]->getArea()) {
                TwoDShape* temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;
            }
        }
    }
    cout << "Done.\n";
}

int main() {
    int choice;

    do {
        cout << "1. Circle\n";
        cout << "2. Square\n";
        cout << "3. Triangle\n";
        cout << "4. Print objects\n";
        cout << "5. Sort by area\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                createCircle();
                break;
            case 2:
                createSquare();
                break;
            case 3:
                createTriangle();
                break;
            case 4:
                displayShapes();
                break;
            case 5:
                sortShapesByArea();
                break;
            case 0:
                cout << "Bye.\n";
                break;
            default:
                cout << "No.\n";
                break;
        }
    } while (choice != 0);

    for (TwoDShape* shape : shapes) {
        delete shape;
    }

    return 0;
}

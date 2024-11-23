#include "shapes.hpp"

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

    Circle* cir = new Circle();
    cir->setX(x);
    cir->setY(y);
    cir->setRadius(radius);

    shapes.push_back(cir);
}

void createSquare() {
    double x, y, sideLength;
    cout << "Enter X, Y, side length of the square: ";
    cin >> x >> y >> sideLength;

    Square* sq = new Square();
    sq->setX(x);
    sq->setY(y);
    sq->setSideLength(sideLength);

    shapes.push_back(sq);
}

void createTriangle() {
    double x, y, sideLength;
    cout << "Enter X, Y, side length of the triangle: ";
    cin >> x >> y >> sideLength;

    Triangle* tri = new Triangle();
    tri->setX(x);
    tri->setY(y);
    tri->setSideLength(sideLength);

    shapes.push_back(tri);
}
void sortShapesByArea() {
    for (int i = 0; i < shapes.size() - 1; ++i) {
        for (int j = 0; j < shapes.size() - i - 1; ++j) {
            if (shapes[j]->getArea() > shapes[j + 1]->getArea()) {
                TwoDShape* temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;
            }
        }
    }
    cout << "Done.\n";
}

void sortShapesByPerimeter() {
    for (int i = 0; i < shapes.size() - 1; ++i) {
        for (int j = 0; j < shapes.size() - i - 1; ++j) {
            if (shapes[j]->getPerimeter() > shapes[j + 1]->getPerimeter()) {
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
        cout << "6. Sort by perimeter";
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
            case 6:
                sortShapesByPerimeter();
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

#include "shapes.hpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<Shape*> shapes;
    bool running = true;

    while (running) {
        std::cout << "\nChoose a shape to create (1 = Circle, 2 = Square, 3 = Triangle, 4 = Print objects, 0 = Exit): ";
        int choice;
        std::cin >> choice;

        Shape* newShape = nullptr;

        switch (choice) {
            case 1: {
                double x, y, radius;
                std::cout << "Enter x, y coordinates and radius: ";
                std::cin >> x >> y >> radius;
                newShape = new Circle(x, y, radius);
                break;
            }
            case 2: {
                double x, y, sideLength;
                std::cout << "Enter x, y coordinates and side length: ";
                std::cin >> x >> y >> sideLength;
                newShape = new Square(x, y, sideLength);
                break;
            }
            case 3: {
                double x, y, sideLength;
                std::cout << "Enter x, y coordinates and side length: ";
                std::cin >> x >> y >> sideLength;
                newShape = new Triangle(x, y, sideLength);
                break;
            }
            case 4:
                std::cout << "Printing all objects:\n";
                for (Shape* shape : shapes) {
                    shape->print();
                }
                continue;
            case 0:
                running = false;
                break;  
            default:
                std::cout << "Try again." << std::endl;
                continue;
        }

        if (newShape) {
            shapes.push_back(newShape);
            std::cout << "\nCreated " << newShape->getName() << " at ("
                      << newShape->getX() << ", " << newShape->getY() << ") with side length "
                      << newShape->getSideLength() << "\n";
        }
    }

    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}
